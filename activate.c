#include "include.h"


void activate (GtkApplication *app, gpointer user_data){
    GtkWidget *window = gtk_application_window_new (app);
    GtkWidget *button1 = gtk_button_new_with_label("+");
    GtkWidget *button2 = gtk_button_new_with_label("-");
    GtkWidget *actionbar = gtk_action_bar_new();
    GtkWidget *fixed1 = gtk_fixed_new();
    GtkWidget *searchh = gtk_search_entry_new();
    GtkWidget *datas = gtk_list_box_new();
    GtkWidget *datasW = gtk_scrolled_window_new(NULL,NULL);


    gtk_window_set_title (GTK_WINDOW (window), "Passlet");
    gtk_window_set_resizable(GTK_WINDOW (window), 0);
    gtk_window_set_default_size(GTK_WINDOW (window), 400, 300);
    gtk_container_set_border_width (GTK_CONTAINER (window), 0);

    gtk_widget_set_size_request(datasW, 380, 300);
    gtk_widget_set_size_request(actionbar, 400, 40);
    gtk_widget_set_size_request(searchh, 380, 40);
    gtk_fixed_put (fixed1, actionbar, 0, 360);
    gtk_fixed_put (fixed1, datasW, 10, 50);
    gtk_fixed_put (fixed1, searchh, 10, 4);

    g_signal_connect(button1, "clicked", G_CALLBACK(addPass), NULL);


    gtk_container_add (GTK_CONTAINER (window), fixed1);
    gtk_container_add (GTK_CONTAINER (datasW), datas);
    gtk_container_add (GTK_CONTAINER (actionbar), button1);
    gtk_container_add (GTK_CONTAINER (actionbar), button2);
    gtk_widget_show_all (window);
}
