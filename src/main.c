#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

typedef struct {
    GtkWidget *w_web_view;              // url_1
    GtkWidget *w_web_view2;             // url_2
    GtkWidget *w_login_web;                 // login to google
    GtkWidget *w_txtvw_main;            // Pointer to text view object
    GtkWidget *w_dlg_file_choose;       // Pointer to file chooser dialog box
    GtkTextBuffer *textbuffer_main;     // Pointer to text buffer
    GtkWidget *w_about_box;             // Pointer to about dialog box
    GtkWidget *w_login_id;              // login window
    GtkWidget *w_window;                // window test
} app_widgets;

int main(int argc, char *argv[])
{
    GtkBuilder          *builder; 
    GtkWidget           *login;
    app_widgets     *widgets = g_slice_new(app_widgets);

gboolean
user_function (WebKitWebView      *web_view,
               WebKitScriptDialog *dialog,
               gpointer            user_data);

    gboolean
    webkit_settings_get_enable_mock_capture_devices (WebKitSettings *settings);

    gboolean
    webkit_user_media_permission_is_for_video_device
                               (WebKitUserMediaPermissionRequest *request);

    gboolean
    webkit_user_media_permission_is_for_audio_device
                               (WebKitUserMediaPermissionRequest *request);

    gtk_init(&argc, &argv);
    
    // Workaround from: https://bugs.webkit.org/show_bug.cgi?id=175937
    //g_object_unref (g_object_ref_sink (webkit_web_view_new ()));
    webkit_web_view_get_type();
    webkit_settings_get_type();

    builder = gtk_builder_new_from_file("glade/ui.glade");
    login = GTK_WIDGET(gtk_builder_get_object(builder, "login_id"));

    widgets->w_web_view  = GTK_WIDGET(gtk_builder_get_object(builder, "url_1"));
    widgets->w_web_view2 = GTK_WIDGET(gtk_builder_get_object(builder, "url_2"));
    widgets->w_about_box = GTK_WIDGET(gtk_builder_get_object(builder, "about_box"));
    widgets->w_login_id = GTK_WIDGET(gtk_builder_get_object(builder, "login_id"));
    widgets->w_login_web = GTK_WIDGET(gtk_builder_get_object(builder, "login_web"));
    widgets->w_window = GTK_WIDGET (gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, widgets);
    webkit_web_view_load_uri(WEBKIT_WEB_VIEW(widgets->w_login_web), "http://accounts.google.com");
    g_object_unref(builder);
    gtk_widget_show_all(login);    
    
    webkit_web_view_load_uri(WEBKIT_WEB_VIEW(widgets->w_web_view), "http://google.com");
    webkit_web_view_load_uri(WEBKIT_WEB_VIEW(widgets->w_web_view2), "http://web.whatsapp.com/");
    gtk_main();
    g_slice_free(app_widgets, widgets);

    return 0;
}

void on_login_id_destroy(GtkWindow *window, app_widgets *app_wdgts)
{
    webkit_web_view_load_uri(WEBKIT_WEB_VIEW(app_wdgts->w_web_view), "http://classroom.google.com");
    gtk_widget_show(app_wdgts->w_window);

}

// Help --> About
void on_about_menu_activate(GtkMenuItem *menuitem, app_widgets *app_wdgts)
{
    gtk_widget_show(app_wdgts->w_about_box);
}

// About dialog box Close button
void on_about_box_response(GtkDialog *dialog, gint response_id, app_widgets *app_wdgts)
{
    gtk_widget_hide(app_wdgts->w_about_box);    
}

//quit
void on_destroy_window_activate(GtkMenuItem *menuitem, app_widgets *app_wdgts)
{
        gtk_main_quit();
}

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}