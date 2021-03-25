#include "include.h"


int main(int argc, char **argv){
    GtkApplication *app = gtk_application_new ("com.massout.passlet", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    return g_application_run (G_APPLICATION (app), argc, argv);
}
