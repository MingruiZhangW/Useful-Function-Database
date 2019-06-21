# JavaScript Knowledge

- Regex.exec(), string.match()<br>
string.match finds the first match and returns it with the actual match, the index at which the text was found and the actual input, when the global flag is not used. string.match just returns all the matches, when the global flag is used.
```
var myString = "[22].[44].[33].";

console.log(myString.match(/\d+/));
# [ '22', index: 1, input: '[22].[44].[33].' ]
console.log(myString.match(/\d+/g));
# [ '22', '44', '33' ]
```
The main difference between string.match and regex.exec is, the regex object will be updated of the current match with regex.exec call. For example,
```
var myString = "[22].[44].[33].", myRegexp = /\d+/g, result;

while (result = myRegexp.exec(myString)) {
    console.log(result, myRegexp.lastIndex);
}
```
will return
```
[ '22', index: 1, input: '[22].[44].[33].' ] 3
[ '44', index: 6, input: '[22].[44].[33].' ] 8
[ '33', index: 11, input: '[22].[44].[33].' ] 13
```
As you can see, the lastIndex property is updated whenever a match is found. So, keep two things in mind when you use exec, or you will run into an infinite loop.

>If you don't use g option, then you will always get the first match, if there is one, otherwise null. So, the following will run into an infinite loop.
```
var myString = "[22].[44].[33].", myRegexp = /\d+/, result;

while (result = myRegexp.exec(myString)) {
    console.log(result, myRegexp.lastIndex);
}
```
Don't forget to use the same regular expression object with subsequent calls. Because, the regex object is updated every time, and if you pass new object, again the program will run into an infinite loop.
```
var myString = "[22].[44].[33].", result;

while (result = /\d+/g.exec(myString)) {
    console.log(result);
}
```
# Delete Parent Element
```
function delete_row(e)
{
    e.parentNode.parentNode.parentNode.removeChild(e.parentNode.parentNode);
}
```
