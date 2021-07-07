on run {input, parameters}
	set file1 to choose file with prompt "Please select the file whose bookmarks are to be copied:"
	set file2 to choose file with prompt "Please select the file to which bookmarks are to pasted:"
	set var1 to POSIX path of file1
	set var2 to POSIX path of file2
	tell application "Terminal"
		do script "pdftk " & var1 & " dump_data output /Users/aditmalhotra/dump.txt" & ";" & "pdftk " & var2 & " update_info /Users/aditmalhotra/dump.txt output /Users/aditmalhotra/Desktop/updated.pdf" & ";" & "rm dump.txt"
		delay 5
		quit
	end tell
	set theDialogText to "Task completed"
	display dialog theDialogText
	return input
end run