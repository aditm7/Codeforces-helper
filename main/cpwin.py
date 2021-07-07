from selenium import webdriver 
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from time import sleep
import os
import sys
from selenium.webdriver.firefox.options import Options
import pdfkit
from io import BytesIO
from PIL import Image
#must end with \
temp="D:\\cp_project\\"   ##write the location of bot files
parent_dir = "D:\\Contests\\" ##write the location of the folder where the files have to be created
config = pdfkit.configuration(wkhtmltopdf="") #wkhtmltopdf file path
options2 = {
    'quiet': '',
    'javascript-delay' : '5000',
    'page-size': 'A4',
    'margin-top': '0.5in',
    'margin-right': '0.5in',
    'margin-bottom': '0.5in',
    'margin-left': '0.5in',
    'dpi': '400',
    'user-style-sheet':temp+"css1.css",
    'minimum-font-size':'20',
}


toc = sys.argv[1]
if toc=='cf' or toc=='CF':
	n = 1
	contests = []
	var = int(sys.argv[2])
	contests.append(var)
	#creating the driver 
	options = Options()
	options.headless = True
	#creating the driver and opening the desired difficulty problems 
	driver = webdriver.Firefox(options=options)

	for i in range(n):
		#input of variables and creating a folder of the same name as contest no
		c = contests[i]
		directory = str(c)
		mainfolder = os.path.join(parent_dir, directory)
		os.mkdir(mainfolder)
		#opening the contest website
		driver.implicitly_wait(1)
		driver.get("https://codeforces.com/contest/" + str(c))

		#a method to find how many problems and thus total no of aplhabets
		element1 = driver.find_elements_by_xpath("//td[@class='id dark left']")
		element2 = driver.find_elements_by_xpath("//td[@class='id left']")
		
		#the last problem can either be in dark or light tag
		try:
			element3 = driver.find_element_by_xpath("//td[@class='id bottom left']")
		except:
			element3 = driver.find_element_by_xpath("//td[@class='id bottom dark left']")	
		finally:
			element = []
			a = len(element1) + len(element2)

			for i in range(0,a):
				if i%2==0:
					element.append(element1[int(i/2)])
				else:
					element.append(element2[int((i//2))])
			a = a+1
			element.append(element3)

			#creating a list of the problem's aplbhabetic codes
			problem = []
			for i in element:
				problem.append(i.text)
			#now iterating every problem one by one and storing the neccessary data
			for j in problem:
				parent_dir1 = parent_dir + str(c) + "\\"
				subfolder = os.path.join(parent_dir1, j)
				os.mkdir(subfolder)  #creating the respective subfolders of problems
				driver.get("https://codeforces.com/contest/" + str(c) + "/problem/" + j)
				driver.implicitly_wait(3)
				#main = driver.find_element_by_class_name("problem-statement")
				#main.screenshot(parent_dir + str(c) + "/" + j + "/" + j + ".png")
				img = Image.open(BytesIO(driver.find_element_by_xpath("//div[@class='problemindexholder']").screenshot_as_png))
				rgb = Image.new('RGB', img.size, (255, 255, 255))
				rgb.paste(img, mask=img.split()[3])
				rgb.save(parent_dir + str(c) + "\\" + j + "\\" + j + ".pdf", "PDF", quality=100,resolution=100)
				IO_list = driver.find_elements_by_tag_name("pre")
				for b in range(len(IO_list)):
					if b%2==0:
						fr = open(parent_dir + str(c) + "\\" + j + "\\input" + str(((b)//2)+1) + ".txt", "w+" )
						fr.write(IO_list[b].text)
						fr.close()
					else:
						fr = open(parent_dir + str(c) + "\\" + j + "\\output" + str(((b)//2)+1) + ".txt", "w+" )
						fr.write(IO_list[b].text)
						fr.close()
				#creating the .cpp files with template for every problem
				with open(temp+"temp.txt", "r") as firstfile, open(parent_dir + str(c) + "\\" + j + "\\a.cpp", "a+") as secondfile:
					for line in firstfile:
						secondfile.write(line)
				firstfile.close()
				secondfile.close()
				output_dump = open(parent_dir+str(var)+"\\"+j+"\\output_dump.txt", "a")
				output_dump.close()
	contest_url = "https://codeforces.com/contest/"+str(var)+"/problems"
	file_name = str(var) + '.pdf'
	pdfkit.from_url(contest_url,r""+parent_dir +str(contests[0])+"\\"+ file_name,options=options2,configuration=config)
	"""try:
		file_name = str(var) + '.pdf'
		html = driver.execute_script('return document.getElementsByClassName("problem-frames")[0].innerHTML;');
	except:
		print("invalid")
	HTML(string = html, base_url = 'https://codeforces.com/').write_pdf(parent_dir +str(contests[0])+"/"+ file_name, stylesheets = [CSS(temp+"css.css")])"""
	driver.quit()

elif toc=='cc' or toc=='CC':
	name = sys.argv[2]
	options = Options()
	options.headless = True
	#creating the driver and opening the desired difficulty problems 
	driver = webdriver.Firefox(options=options)

	directory = name
	mainfolder = os.path.join(parent_dir, directory)
	os.mkdir(mainfolder)

	#driver.implicitly_wait(1)
	driver.get("https://www.codechef.com/" + name)
	element2 = driver.find_elements_by_xpath("//td[@class='cc-problem-name']")
	element=[]
	for i in element2:
		if i.find_element_by_xpath(".//a[@class='ember-view']")!='':
			element.append(i.find_element_by_xpath(".//a[@class='ember-view']"))

	urls=[]
	for i in element:
		urls.append(i.get_attribute('href'))

	problems=[]
	count=1;
	for i in element:
		problems.append(str(count)+"_"+i.get_attribute('title'))
		count+=1

	for i in range(len(element)):
		parent_dir1 = parent_dir + name + "\\"
		subfolder = os.path.join(parent_dir1, problems[i])
		os.mkdir(subfolder)  #creating the respective subfolders of problems
		driver.get(urls[i])
		driver.implicitly_wait(1)
		if i==0:
			button = driver.find_element_by_id("gdpr-i-love-cookies")
			button.click()
		driver.implicitly_wait(1)
		#main = driver.find_element_by_xpath("//div[@class='problem-statement mathjax-support']")
		#main.screenshot(parent_dir1 + problems[i] + "/" + problems[i] + ".png")
		img = Image.open(BytesIO(driver.find_element_by_xpath("//div[@class='problem-statement mathjax-support']").screenshot_as_png))
		rgb = Image.new('RGB', img.size, (255, 255, 255))
		rgb.paste(img, mask=img.split()[3])
		rgb.save(parent_dir1 + problems[i] + "\\" + problems[i] + ".pdf", "PDF", quality=100,resolution=100)
		IO_list = driver.find_elements_by_tag_name("code")
		for b in range(len(IO_list)):
			if b%2==0:
				fr = open(parent_dir1 + problems[i] + "\\input" + str(((b)//2)+1) + ".txt", "w+" )
				fr.write(IO_list[b].text)
				fr.close()
			else:
				fr = open(parent_dir1 + problems[i] + "\\output" + str(((b)//2)+1) + ".txt", "w+" )
				fr.write(IO_list[b].text)
				fr.close()
		with open(temp+"temp.txt", "r") as firstfile, open(parent_dir1 + problems[i]+ "\\a.cpp", "a+") as secondfile:
			for line in firstfile:
				secondfile.write(line)
			secondfile.write("\n//Submit it on:\n")
			secondfile.write("//"+driver.find_element_by_xpath("//a[@class='button blue mathjax-support']").get_attribute('href'))
		firstfile.close()
		secondfile.close()
		output_dump = open(parent_dir1 + problems[i]+"\\output_dump.txt", "a")
		output_dump.close()
	driver.quit()
