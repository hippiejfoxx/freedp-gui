	

    /*
     * Compile me with:
     * 	cc -o tut tut.c $(pkg-config --cflags --libs gtk+-2.0 gmodule-2.0)
     */
    #include <string.h>
    #include <gtk/gtk.h>

    GtkBuilder *builder;

    int clicker (GtkWidget *widget, gpointer   data)
    { 
	char execute[160];
  	const gchar* server_entry;
	const gchar* username_entry;
	const gchar* password_entry;

	server_entry = gtk_entry_get_text(GTK_ENTRY((GtkWidget *) gtk_grid_get_child_at((GtkGrid *) data, (gint) 1,(gint) 0 )));
	username_entry = gtk_entry_get_text(GTK_ENTRY((GtkWidget *) gtk_grid_get_child_at((GtkGrid *) data, (gint) 1,(gint) 1 )));
	password_entry = gtk_entry_get_text(GTK_ENTRY((GtkWidget *) gtk_grid_get_child_at((GtkGrid *) data, (gint) 1,(gint) 2 )));
	
	strcpy(execute, "xfreerdp ");
	strcat(execute, "/v ");
	strcat(execute, server_entry);
	strcat(execute, " ");
	strcat(execute, "/u ");
	strcat(execute, username_entry);
	strcat(execute, " /p ");
	strcat(execute, password_entry);
	
	g_print("%s\n", execute);
    }
 
    int main(int argc, char **argv )
    {
        GtkWidget  *window;
        GError     *error = NULL;
     
        /* Init GTK+ */
        gtk_init( &argc, &argv );
     
        /* Create new GtkBuilder object */
        builder = gtk_builder_new();
        /* Load UI from file. If error occurs, report it and quit application.
         * Replace "tut.glade" with your saved project. */
        if( ! gtk_builder_add_from_file( builder, "builder.ui", &error ) )
        {
            g_warning( "%s", error->message );
            g_free( error );
            return( 1 );
        }
     
        /* Get main window pointer from UI */
        window = GTK_WIDGET( gtk_builder_get_object( builder, "window1" ) );
     
        /* Connect signals */
        gtk_builder_connect_signals( builder, NULL );
     
        /* Destroy builder, since we don't need it anymore */
        g_object_unref( G_OBJECT( builder ) );
    
        /* Show window. All other widgets are automatically shown by GtkBuilder */
        gtk_widget_show( window );
     
        /* Start main loop */
        gtk_main();
     
        return( 0 );
    }


