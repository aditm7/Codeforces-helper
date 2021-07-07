on run {input, parameters}
	set var to item 1 of input
	tell application "Terminal"
		do script "cd Documents" & ";" & "cd Competitive_programming" & ";" & "cd contest" & ";" & "mkdir " & var & "" & ";" & "cd " & var & "" & ";" & "mkdir brutef_codes pdfs getio bin" & ";" & "cp /Users/aditmalhotra/Documents/Competitive_programming/bot/temp.cpp ./getio/template.cpp" & ";" & "cp /Users/aditmalhotra/Documents/Competitive_programming/bot/gen.cpp ./getio/generator.cpp" & ";" & "touch ./getio/input.ini ./getio/output.out ./getio/error.log" & ";" & "code . ;exit"
		delay 1
		do script "python3 cp.py " & var & ";exit"
	end tell
	tell application "Visual Studio Code" to activate
	tell application "System Events"
		keystroke "f" using {command down, control down}
	end tell
	delay 1
	tell application "Visual Studio Code" to activate
	tell application "System Events"
		keystroke "o" using {command down, option down}
	end tell
	return input
end run