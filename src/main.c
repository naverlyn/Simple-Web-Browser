#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

typedef struct {
    GtkWidget *w_web_view;
    GtkWidget *w_web_view2;
} app_widgets;

//if it's run, then leave it alone. don't messed up anything, just leave it run.
int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;
    app_widgets     *widgets = g_slice_new(app_widgets);

    gtk_init(&argc, &argv);
    
    // Workaround from: https://bugs.webkit.org/show_bug.cgi?id=175937
    //g_object_unref (g_object_ref_sink (webkit_web_view_new ()));
    webkit_web_view_get_type();
    webkit_settings_get_type();

    builder = gtk_builder_new_from_file("glade/ui.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    widgets->w_web_view  = GTK_WIDGET(gtk_builder_get_object(builder, "url_1"));
    widgets->w_web_view2 = GTK_WIDGET(gtk_builder_get_object(builder, "url_2"));
    
    gtk_builder_connect_signals(builder, widgets);
    
    webkit_web_view_load_uri(WEBKIT_WEB_VIEW(widgets->w_web_view), "http://classroom.google.com");
    webkit_web_view_load_uri(WEBKIT_WEB_VIEW(widgets->w_web_view2), "http://meet.google.com");

    g_object_unref(builder);

    gtk_widget_show_all(window);
    gtk_main();
    g_slice_free(app_widgets, widgets);

    return 0;
}

//test
// void on_window_main_activate_default()
// {

// }

// User presses Enter in the URL bar
// void on_url_entry_activate(GtkEntry *entry, app_widgets *app_wdgts)
// {
//     const gchar *the_url;
//     const gchar *the_url2;
    
//     the_url = gtk_entry_get_text(entry);
    
//     webkit_web_view_load_uri(WEBKIT_WEB_VIEW(app_wdgts->w_web_view), the_url);
// }
// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}