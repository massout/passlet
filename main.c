#include <gtk/gtk.h>

void activate (GtkApplication *app, gpointer user_data);

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


int main(int argc, char **argv){
    GtkApplication *app = gtk_application_new ("com.massout.passlet", G_APPLICATION_FLAGS_NONE);

    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);

    return g_application_run (G_APPLICATION (app), argc, argv);
}

