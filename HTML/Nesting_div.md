Nesting Divs
 30 MAY 2017  Tutorials
If you want to learn about HTML and CSS, then you are certain to encounter div tags and classes when you are working. Divs are divisions or block areas where content is contained.

Think of a div as a block, where you can place content. You can specify a div’s width, height, color, and more with CSS. You can place divs inside of other divs, and that is called nesting. You can two types of divs- div tags and div classes.

A regular div is a block element that you want to place on the page once. A great example would be the footer of a website. You only want the footer to appear once on a site at the bottom of the page. In the HTML, you create a div with the id of footer. In your CSS, you will call the footer div id by putting # in front of the id that you gave that particular div.

The HTML
<div id="container">  
<div class="menu">  
    <ul>
        <li><a href="#" >Home</a></li>
        <li><a href="#" id="current">Fruit</a>
            <ul>
                <li><a href="#">Apples</a></li>
                <li><a href="#">Oranges</a></li>
                <li><a href="#">Bananas</a></li>
                <li><a href="#">Pears</a></li>
            </ul>
        </li>
        <li><a href="/about.html">About</a>
            <ul>
                <li><a href="#">Company Info</a></li>
                <li><a href="#">Locations</a></li>
                <li><a href="#">FAQ</a></li>
            </ul>
        </li>
        <li><a href="/contact/contact.php">Contact Us</a></li>
    </ul>
</div><!--closing div class for "menu"-->  
</div><!--closing div for "container"-->  
The CSS
I am not including the CSS for the drop downs and the rest of the menu to try to cut down on confusion. Our focus is to look at how the main divs interact with each other. If you wish to see how the CSS is structured for a full CSS3 drop down menu, view our recent tutorial here.

#container    {
    width:1024px;
    background: #CCC;
    height:400px;
    margin:auto;
}
.menu{
    width:960px;
    border:none;
    border:0px;
    margin:auto;
    padding:0px;
    font: 67.5% "Lucida Sans Unicode", "Bitstream Vera Sans", "Trebuchet Unicode MS", "Lucida Grande", Verdana, Helvetica, sans-serif;
    font-size:14px;
    font-weight:bold;
    }


You will notice from the example that the container div, where the contents of the site are contained, is 1024px wide. The menu div class is nested inside of the container div, where we centered it's position. This is a common technique with CSS, using a container div to contain or the main contents of the site, to that it has a uniform appearance and it is easy to align elements.

A div class is different. You can call a div class as many times as you’d like in your html. This is great for repeating divs, such as menu items and elements with multiple sections. You create a div class in html by using the phrase div class=”(put your class name here)”. It is just as easy to apply a style to a class as it is a regular div. Simply use a “.” before the class name in your CSS file to style that class.
