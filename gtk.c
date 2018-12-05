#include<gtk/gtk.h>

char *filename = "";
gchar *saved_file = "";
char *blank = "blank.png";
GtkWidget *window;
GtkWidget *pop;
GtkWidget *image;
GtkWidget *vbox;
GtkWidget *entry;
GtkWidget *frame;


gboolean draw_picture(GtkWidget *da, cairo_t *cr, gpointer data)
{
    gint width = gtk_widget_get_allocated_width(da);
    gint height = gtk_widget_get_allocated_height(da);

    GdkPixbuf *temp = gdk_pixbuf_scale_simple((GdkPixbuf*)data, width, height, GDK_INTERP_BILINEAR);
    gdk_cairo_set_source_pixbuf(cr, temp, 0, 0);
    gtk_widget_queue_draw(da);
    cairo_paint(cr);

    g_object_unref(temp);
    return FALSE;
}

static void clear (GtkWidget *da, cairo_t *cr, gpointer data)
{
    gint width = gtk_widget_get_allocated_width(frame);
    gint height = gtk_widget_get_allocated_height(frame);
    gtk_widget_queue_draw(da);
    cairo_set_source_rgb (cr, 1, 1, 1);
    cairo_paint (cr);

}

static void fclean (GtkWidget *da, cairo_t *cr, gpointer data)
{
    GdkPixbuf *temp = gdk_pixbuf_new_from_file_at_size(blank, 100,100, NULL);
    g_signal_connect(frame, "draw", G_CALLBACK(clear), NULL);
}

static void Get_Dialog (GtkWidget *parent)
{
    GtkWidget *dialog;
    GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;
    gint res;

    dialog = gtk_file_chooser_dialog_new ("Open File",
                                          parent,
                                          action,
                                          ("_Cancel"),
                                          GTK_RESPONSE_CANCEL,
                                          ("_Open"),
                                          GTK_RESPONSE_ACCEPT,
                                          NULL);
    res = gtk_dialog_run (GTK_DIALOG (dialog));

    if (res == GTK_RESPONSE_ACCEPT)
    {

        GtkFileChooser *chooser = GTK_FILE_CHOOSER (dialog);
        filename = gtk_file_chooser_get_filename (chooser);

        GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file(filename, NULL);

        gtk_widget_set_hexpand(frame, TRUE);
        gtk_widget_set_vexpand(frame, TRUE);
        g_signal_connect(frame, "draw", G_CALLBACK(draw_picture), pixbuf);
        gtk_widget_set_size_request (frame, 600, 600);

        opendir (filename);
        g_free (filename);

    }
    gtk_widget_destroy (dialog);
}

static void Get_Folder (GtkWindow *parent)
{

    GtkWidget *dialog;
    GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER;
    gint res;

    dialog = gtk_file_chooser_dialog_new ("Open File",
                                          parent,
                                          action,
                                          ("_Cancel"),
                                          GTK_RESPONSE_CANCEL,
                                          ("_Open"),
                                          GTK_RESPONSE_ACCEPT,
                                          NULL);

    res = gtk_dialog_run (GTK_DIALOG (dialog));
    if (res == GTK_RESPONSE_ACCEPT)
    {
        GtkFileChooser *choice = GTK_FILE_CHOOSER(dialog);
        gtk_file_chooser_set_action (choice,action);
        saved_file = gtk_file_chooser_get_filename(choice);
        printf("%s \n",saved_file);

    }
    gtk_widget_destroy (dialog);
}


static void Ocr (GtkWindow *parent)
{

}

int main(int argc, char *argv[])
{

    gtk_init(&argc, &argv);

    image = gtk_image_new();
    GtkWidget *canvas;


    GtkWidget *box_1;
    GtkWidget *box_2;


    GtkWidget *toolbar;
    GtkToolItem *newTb;
    GtkToolItem *openTb;
    GtkToolItem *saveTb;
    GtkToolItem *sep;
    GtkToolItem *exitTb;
    GtkWidget *halign;
    GtkWidget *valign;

    GtkWidget *container = NULL;

    GtkWidget *okBtn;


    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_widget_set_size_request(window, 500, 500);
    gtk_container_set_border_width (GTK_CONTAINER (window), 5);
    gtk_window_set_resizable(GTK_WINDOW(window),FALSE);
    gtk_window_set_title(GTK_WINDOW(window), "OCR");

    vbox = gtk_vbox_new(FALSE, 1);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    toolbar = gtk_toolbar_new();
    gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS);

    newTb = gtk_tool_button_new_from_stock(GTK_STOCK_NEW);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), newTb, -1);

    openTb = gtk_tool_button_new_from_stock(GTK_STOCK_OPEN);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), openTb, -1);

    saveTb = gtk_tool_button_new_from_stock(GTK_STOCK_SAVE);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), saveTb, -1);

    sep = gtk_separator_tool_item_new();
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), sep, -1);

    exitTb = gtk_tool_button_new_from_stock(GTK_STOCK_QUIT);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), exitTb, -1);

    gtk_container_add(vbox,toolbar);


    frame = gtk_frame_new (NULL);
    GtkWidget *da1 = gtk_drawing_area_new();
    gtk_widget_set_size_request(da1, 400, 400);
    gtk_container_add(frame,da1);
    gtk_frame_set_shadow_type (GTK_FRAME (frame), GTK_SHADOW_OUT);
    gtk_container_add(GTK_CONTAINER(vbox), frame);


    g_signal_connect(G_OBJECT(exitTb), "clicked", G_CALLBACK(gtk_main_quit), NULL);

    g_signal_connect(newTb, "clicked", G_CALLBACK(fclean), frame);

    g_signal_connect(G_OBJECT(openTb), "clicked", G_CALLBACK(Get_Dialog), frame);
    g_signal_connect(G_OBJECT(saveTb), "clicked", G_CALLBACK(Get_Folder), NULL);

    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);



    box_1 = gtk_vbox_new(FALSE, 5);

    valign = gtk_alignment_new(1, 0, 0, 0);
    gtk_container_add(GTK_CONTAINER(box_1), valign);
    gtk_container_add(GTK_CONTAINER(vbox), box_1);

    box_2 = gtk_hbox_new(TRUE, 3);

    okBtn = gtk_button_new_with_label("Launch");
    gtk_widget_set_size_request(okBtn, 150, 50);
    gtk_container_add(GTK_CONTAINER(box_2), okBtn);

    halign = gtk_alignment_new(1, 0, 0, 0);
    gtk_container_add(GTK_CONTAINER(halign), box_2);

    gtk_box_pack_start(GTK_BOX(box_1), halign, FALSE, FALSE, 0);
    g_signal_connect(G_OBJECT(window), "clicked", G_CALLBACK(Ocr), NULL);


    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}