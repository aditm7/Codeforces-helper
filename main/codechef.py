from selenium import webdriver 
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from time import sleep
import os
from selenium.webdriver.firefox.options import Options
from weasyprint import HTML, CSS

parent_dir = "/Users/aditmalhotra/Documents/Competitive_programming/contest/"
temp="/Users/aditmalhotra/Documents/Competitive_programming/bot/"

name = input("enter contest name")
options = Options()
options.headless = True
#creating the driver and opening the desired difficulty problems 
driver = webdriver.Firefox(options=options)

directory = name
mainfolder = os.path.join(parent_dir, directory)
os.mkdir(mainfolder)

driver.implicitly_wait(1)
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
for i in element:
	problems.append(i.get_attribute('title'))

for i in range(len(element)):
	parent_dir1 = parent_dir + name + "/"
	subfolder = os.path.join(parent_dir1, problems[i])
	os.mkdir(subfolder)  #creating the respective subfolders of problems
	driver.get(urls[i])
	driver.implicitly_wait(1)
	if i==0:
		button = driver.find_element_by_id("gdpr-i-love-cookies")
		button.click()
	main = driver.find_element_by_xpath("//div[@class='problem-statement mathjax-support']")
	main.screenshot(parent_dir1 + problems[i] + "/" + problems[i] + ".png")
	IO_list = driver.find_elements_by_tag_name("code")
	for b in range(len(IO_list)):
		if b%2==0:
			fr = open(parent_dir1 + problems[i] + "/input" + str(((b)//2)+1) + ".txt", "w+" )
			fr.write(IO_list[b].text)
			fr.close()
		else:
			fr = open(parent_dir1 + problems[i] + "/output" + str(((b)//2)+1) + ".txt", "w+" )
			fr.write(IO_list[b].text)
			fr.close()
	with open(temp+"temp.txt", "r") as firstfile, open(parent_dir1 + problems[i]+ "/a.cpp", "a+") as secondfile:
		for line in firstfile:
			secondfile.write(line)
		secondfile.write("\n//Submit it on:\n")
		secondfile.write("//"+driver.find_element_by_xpath("//a[@class='button blue mathjax-support']").get_attribute('href'))
	firstfile.close()
	secondfile.close()
	output_dump = open(parent_dir1 + problems[i]+"/output_dump.txt", "a")
	output_dump.close()
driver.quit()













