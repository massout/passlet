#include "include.h"


void addPass(GtkWidget *widget, gpointer user_data){
    GtkWidget *window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);;
    GtkWidget *giris1 = gtk_entry_new();
    GtkWidget *giris2 = gtk_entry_new();
    GtkWidget *giris3 = gtk_entry_new();
    GtkWidget *onayButton = gtk_button_new_with_label("SAVE");
    GtkWidget *fixed2 = gtk_fixed_new();



    gtk_window_set_title(GTK_WINDOW(window1),"Add Password to Your Wallet");
    gtk_window_set_resizable(GTK_WINDOW (window1), 0);
    gtk_window_set_default_size(GTK_WINDOW (window1), 710, 50);
    gtk_window_set_modal (window1, 1);

    gtk_entry_set_placeholder_text (giris1, "INPUT 1");
    gtk_entry_set_placeholder_text (giris2, "INPUT 2");
    gtk_entry_set_placeholder_text (giris3, "INPUT 3");

    gtk_widget_set_size_request(giris1, 200, 30);
    gtk_widget_set_size_request(giris2, 200, 30);
    gtk_widget_set_size_request(giris3, 200, 30);
    gtk_widget_set_size_request(onayButton, 50, 30);
    gtk_fixed_put(fixed2, giris1, 10, 10);
    gtk_fixed_put(fixed2, giris2, 220, 10);
    gtk_fixed_put(fixed2, giris3, 430, 10);
    gtk_fixed_put(fixed2, onayButton, 640, 10);

    gtk_container_add (GTK_CONTAINER (window1), fixed2);
    gtk_widget_show_all (window1);
}
