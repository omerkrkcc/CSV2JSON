# CSV2JSON

CSV2JSON is a program written in C language and can be used to create any file written in CSV format. 
allows you to easily convert to JSON format.

## Usage
1- Extract the file from the rar.
2- You must have downloaded "tdm gcc" for the program to run.
3- After running Command Prompt, cd command to the directory with CSV2JSON.exe inside the folder.
4- After following the instructions above, run gcc -o CSV2JSON CSV2JSON.c.
5- Then CSV2JSON [input.csv] [output.json] [header=ON | OFF]
6- This way json is created in the relevant directory. 
7- The names of input.csv and output.json files must contain only English characters.
8- It is not a problem to have Turkish characters in the file content

Example run,
C:\Users\UserName> cd Desktop\CSV2JSON 
C:\Users\UserName\Desktop\CSV2JSON> gcc -o CSV2JSON CSV2JSON.c
C:\Users\UserName\Desktop\CSV2JSON> CSV2JSON deneme.csv output.json header=ON


## Contribution
All contributions are welcome. For major changes, please specify what you want to change.

## Lisans
MIT License Copyright (c) [2022] [OMER KARAKECE]
 Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
and associated documentation files (the "Software"), to deal in the Software without restriction, 
including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, 
subject to the following conditions: The above copyright notice and this permission notice shall be 
included in all copies or substantial portions of the Software. THE SOFTWARE IS PROVIDED "AS IS", 
WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS 
OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
IN THE SOFTWARE.
