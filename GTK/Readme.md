# GTK Knowledge

### GTK Grab Focus
```
gtk_widget_set_can_focus and  gtk_widget_grab_focus

gtk_widget_set_can_focus ()
void
gtk_widget_set_can_focus (GtkWidget *widget,
                          gboolean can_focus);
Specifies whether widget can own the input focus. See gtk_widget_grab_focus() for actually setting the input focus on a widget.

Parameters
widget

a GtkWidget

 
can_focus

whether or not widget can own the input focus.

 
Since: 2.18
```
### Mouse Event Handling

> button-press-event
```
https://developer.gnome.org/gtk-tutorial/stable/x2431.html
https://developer.gnome.org/gtk-tutorial/stable/x334.html
```
