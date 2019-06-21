# HTML Knowledge
### Img Base 64
```
<div>
    <p>Taken from wikpedia</p>
    <img src="data:image/png;base64, iVBORw0KGgoAAAANSUhEUgAAAAUA
AAAFCAYAAACNbyblAAAAHElEQVQI12P4//8/w38GIAXDIBKE0DHxgljNBAAO
    9TXL0Y4OHwAAAABJRU5ErkJggg==" alt="Red dot" />
</div> 
You can try this base64 decoder to see if your base64 data is correct or not.
```

### Editiable div place holder
```
Here is a pure CSS only solution:-

<div contentEditable=true data-ph="My Placeholder String"></div>
<style>
    [contentEditable=true]:empty:not(:focus):before{
        content:attr(data-ph)
    }
</style>
Here, we basically select all contentEditable <divs> that are empty & blurred. We then create a pseudo element before the CSS selection (the editable div) and fix our placeholder text (specified the data-ph attribute) as its content.
```
### Overflow scroll bar - overlay
DISCLAIMER: overlay has been deprecated.
You can still use this if you absolutely have to, but try not to.

This only works on WebKit browsers, but I like it a lot. Will behave like auto on other browsers.
```
.yourContent{
   overflow-y: overlay;
}
```
This will make the scrollbar appear only as an overlay, thus not affecting the width of your element!
