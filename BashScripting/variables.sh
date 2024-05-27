#!/bin/bash



#Shebang Syntax: The shebang consists of the characters #! followed by the path to the interpreter that should be used to execute the script.
#The line !/bin/bash is called a shebang or hashbang. 
#Its a special construct at the beginning of a script file that tells the system which interpreter to use to execute the script. 
#In this case, /bin/bash specifies that the script should be executed using the Bash interpreter located at /bin/bash





# Scalar Variables
name="John"
age=25
price=10.99



# echo statement is used to output things on screen


echo "Scalar Variables:"
echo "Name: $name"
echo "Age: $age"
echo "Price: $price"
echo

# Arrays
fruits=("apple" "banana" "cherry")

echo "Arrays:"
echo "First fruit: ${fruits[0]}"
echo "Second fruit: ${fruits[1]}"
echo "Third fruit: ${fruits[2]}"
echo

# Associative Arrays (Requires Bash version 4+)
declare -A person
person[name]="John"
person[age]=25

echo "Associative Arrays:"
echo "Name: ${person[name]}"
echo "Age: ${person[age]}"
echo

# Environment Variables
echo "Environment Variables:"
echo "Home directory: $HOME"
echo "User: $USER"
echo

# Special Variables
echo "Special Variables:"
echo "Process ID: $$"
echo "Script name: $0"
echo "Number of arguments: $#"
echo "Exit status: $?"
echo

# Variable Substitution
echo "Variable Substitution:"
echo "Hello, ${name:-Guest}"  # Outputs: "Hello, John"
unset name
echo "Hello, ${name:-Guest}"  # Outputs: "Hello, Guest"
echo

# Read-only Variables
readonly VERSION="1.0"
echo "Read-only Variable:"
echo "Version: $VERSION"
echo

# Default Values in Variable Assignment
unset greeting
echo "Default Values in Variable Assignment:"
echo "Greeting: ${greeting:-Hello}"
greeting="Hi"
echo "Greeting: ${greeting:-Hello}"
echo

# Indirect References
foo="bar"
bar="Hello, World!"
echo "Indirect References:"
echo "Value of foo: ${!foo}"  # Outputs: "Hello, World!"
echo

# Variable Indirection
var_name="foo"
foo="Hello, Bash!"
echo "Variable Indirection:"
echo "Value of $var_name: ${!var_name}"  # Outputs: "Hello, Bash!"
echo

# Variable Length
echo "Variable Length:"
str="Hello, Bash!"
echo "Length of string: ${#str}"  # Outputs: 12
echo

# Unsetting Variables
unset str
echo "Unsetting Variables:"
echo "Value of str: $str"  # Outputs nothing
echo

# Null Command
: '
This is a multi-line comment.
Null command ":" does nothing, but it's a placeholder.
Useful for commenting out blocks of code.
'
echo "Null Command:"
:  # Null command
echo "This line is executed"
echo

# Parameter Expansion
echo "Parameter Expansion:"
echo "Username: ${USER:-guest}"  # Outputs: "Username: <current user>"
echo "Home directory: ${HOME:-/home/guest}"  # Outputs: "Home directory: <home directory>"
echo

# Here Document
echo "Here Document:"
cat << EOF
This is a here document.
It allows you to easily include multi-line text in your script.
EOF
echo

# Here String
echo "Here String:"
string="Hello, World!"
while read -r line; do
    echo "Line read: $line"
done <<< "$string"
echo

# Command Substitution
echo "Command Substitution:"
files=$(ls)
echo "Files in current directory:"
echo "$files"
echo

# Arithmetic Expansion
echo "Arithmetic Expansion:"
a=5
b=3
echo "a + b = $((a + b))"  # Outputs: "a + b = 8"
echo

# String Manipulation
echo "String Manipulation:"
str="Hello, World!"
echo "Length of string: ${#str}"  # Outputs: "Length of string: 13"
echo "Substring: ${str:7}"  # Outputs: "World!"
echo "Substring with length: ${str:7:5}"  # Outputs: "World"
echo "Substring from the end: ${str: -6}"  # Outputs: "World!"
echo "Replace first occurrence: ${str/World/Universe}"  # Outputs: "Hello, Universe!"
echo "Replace all occurrences: ${str//o/O}"  # Outputs: "HellO, WOrld!"
echo "Trim leading whitespace: ${str##* }"  # Outputs: "World!"
echo "Trim trailing whitespace: ${str%% *}"  # Outputs: "Hello,"
echo

# Case Modification
echo "Case Modification:"
str="hello world"
echo "Uppercase: ${str^^}"  # Outputs: "HELLO WORLD"
echo "Lowercase: ${str,,}"  # Outputs: "hello world"
echo "Capitalize: ${str^}"   # Outputs: "Hello world"
echo

# Concatenation
echo "Concatenation:"
str1="Hello"
str2="World!"
echo "${str1}, ${str2}"  # Outputs: "Hello, World!"
echo

# Append to String
echo "Append to String:"
str="Hello"
str+=" Bash!"
echo "$str"  # Outputs: "Hello Bash!"
echo

# Multiline Strings
echo "Multiline Strings:"
multiline_str="This is a
multiline string"
echo "$multiline_str"
echo

# String Length in Multiline Strings
echo "String Length in Multiline Strings:"
multiline_str="This is a
multiline string"
echo "Length of multiline string: ${#multiline_str}"  # Outputs: Length of multiline string: 29
echo

# Escape Sequences
echo "Escape Sequences:"
echo "Hello,\nBash!"  # Outputs: "Hello,\nBash!"
echo -e "Hello,\nBash!"  # Outputs: "Hello," (newline) "Bash!"
echo

# Custom Delimiter in `read` Command
echo "Custom Delimiter in 'read' Command:"
read -d ',' var <<< "apple,banana,cherry"
echo "First fruit: $var"  # Outputs: "First fruit: apple"
echo

# Using `declare` to Set Attributes
echo "Using 'declare' to Set Attributes:"
declare -r const_var="This is a constant"
declare -i int_var=10
declare -a arr_var=("apple" "banana" "cherry")
declare -A assoc_arr_var=([name]="John" [age]=25)
echo

# Display All Variables
echo "Display All Variables:"
declare
echo

# Unset Specific Variables
echo "Unset Specific Variables:"
unset const_var int_var arr_var assoc_arr_var
echo

# Display All Variables Again
echo "Display All Variables After Unset:"
declare
