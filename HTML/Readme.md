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

You can stablish specific toolbar for div
```
div::-webkit-scrollbar {
    width: 12px;
}
```
### How to center and crop an image to always appear in square shape with CSS?
object-fit property does the magic.
CSS
```
.image {
  width: 160px;
  height: 160px;
}

.object-fit_fill {
  object-fit: fill
}

.object-fit_contain {
  object-fit: contain
}

.object-fit_cover {
  object-fit: cover
}

.object-fit_none {
  object-fit: none
}

.object-fit_scale-down {
  object-fit: scale-down
}
```
HTML
```
<div class="original-image">
  <p>original image</p>
  <img src="http://lorempixel.com/500/200">
</div>

<div class="image">
  <p>object-fit: fill</p>
  <img class="object-fit_fill" src="http://lorempixel.com/500/200">
</div>

<div class="image">
  <p>object-fit: contain</p>
  <img class="object-fit_contain" src="http://lorempixel.com/500/200">
</div>

<div class="image">
  <p>object-fit: cover</p>
  <img class="object-fit_cover" src="http://lorempixel.com/500/200">
</div>

<div class="image">
  <p>object-fit: none</p>
  <img class="object-fit_none" src="http://lorempixel.com/500/200">
</div>

<div class="image">
  <p>object-fit: scale-down</p>
  <img class="object-fit_scale-down" src="http://lorempixel.com/500/200">
</div>
```
Result <br>
[![N|Solid](https://i.stack.imgur.com/HCG3I.png)](https://nodesource.com/products/nsolid)

### overflow:scroll and The Right Padding Problem - A CSS Only Solution

[![N|Solid](https://cdn-images-1.medium.com/max/800/1*_O3aWkD0UfmgrlBkL5SEnA.png
)](https://nodesource.com/products/nsolid)

it's possible to create the margins with pseudo-elements:
```
.outer::before { content: ' '; min-width: 5px; }
.outer::after { content: ' '; min-width: 5px; }
.outer {
    display: flex;
    flex-direction: row;
    width: 300px;
    height: 80px;
    border:1px #ccc solid;
    overflow-x: auto;
    padding: 5px;
}
.outer::after { content: ' '; min-width: 5px; }
.outer > div {
    flex: 1 1 auto;
    border: 1px #ccc solid;
    text-align: center;
    min-width: 50px;
    margin: 5px;
}
```
```
<div class="outer">
    <div>text1</div>
    <div>text2</div>
    <div>text3</div>
    <div>text4</div>
    <div>text5</div>
    <div>text6</div>
    <div>text7</div>
    <div>text8</div>
    <div>text9</div>
    <div>text10</div>
</div>
```
