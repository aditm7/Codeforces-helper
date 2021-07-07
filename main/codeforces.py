from selenium import webdriver 
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from time import sleep
import os
from weasyprint import HTML, CSS
import sys
from selenium.webdriver.firefox.options import Options
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
	parent_dir = "/Users/aditmalhotra/Documents/Competitive_programming/contest/"
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
			parent_dir1 = parent_dir + str(c) + "/"
			subfolder = os.path.join(parent_dir1, j)
			os.mkdir(subfolder)  #creating the respective subfolders of problems
			driver.implicitly_wait(2)
			driver.get("https://codeforces.com/contest/" + str(c) + "/problem/" + j)
			sleep(1)
			#creating the screenshot of the problem part only and not the whole page
			main = driver.find_element_by_class_name("problem-statement")
			if j=="A":
				print(main)
			main.screenshot(parent_dir + str(c) + "/" + j + "/" + j + ".png")
			#storing the input and output of sample test runs in the text files
			IO_list = driver.find_elements_by_tag_name("pre")
			for b in range(len(IO_list)):
				if b%2==0:
					fr = open(parent_dir + str(c) + "/" + j + "/input" + str(((b)//2)+1) + ".txt", "w+" )
					fr.write(IO_list[b].text)
					fr.close()
				else:
					fr = open(parent_dir + str(c) + "/" + j + "/output" + str(((b)//2)+1) + ".txt", "w+" )
					fr.write(IO_list[b].text)
					fr.close()
			#creating the .cpp files with template for every problem
			with open("/Users/aditmalhotra/Documents/Competitive_programming/bot/temp.txt", "r") as firstfile, open(parent_dir + str(c) + "/" + j + "/a.cpp", "a+") as secondfile:
				for line in firstfile:
					secondfile.write(line)
			firstfile.close()
			secondfile.close()
			output_dump = open("/Users/aditmalhotra/Documents/Competitive_programming/contest/"+str(var)+"/"+j+"/output_dump.txt", "a")
			output_dump.close()
contest_url = "https://codeforces.com/contest/"+str(var)+"/problems"
driver.get(contest_url)
try:
	file_name = str(var) + '.pdf'
	html = driver.execute_script('return document.getElementsByClassName("problem-frames")[0].innerHTML;');
except:
	print("invalid")
HTML(string = html, base_url = 'https://codeforces.com/').write_pdf(parent_dir +str(contests[0])+"/"+ file_name, stylesheets = [CSS("/Users/aditmalhotra/Documents/Competitive_programming/bot/css.css")])
driver.quit()

pdfkit.from_url("https://codeforces.com/contest/"+str(var)+"/problems",parent_dir + str(var)+"/"+str(var)+"_2.pdf")


