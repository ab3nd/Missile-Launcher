/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_MainWindow (void)
{
  GtkWidget *MainWindow;
  GtkWidget *vbox1;
  GtkWidget *menubar1;
  GtkWidget *menuitem1;
  GtkWidget *menuitem1_menu;
  GtkWidget *quit1;
  GtkWidget *menuitem4;
  GtkWidget *menuitem4_menu;
  GtkWidget *about1;
  GtkWidget *table1;
  GtkWidget *buttonUp;
  GtkWidget *alignment1;
  GtkWidget *hbox1;
  GtkWidget *image1;
  GtkWidget *label1;
  GtkWidget *buttonLeft;
  GtkWidget *alignment5;
  GtkWidget *hbox5;
  GtkWidget *image5;
  GtkWidget *label5;
  GtkWidget *buttonFire;
  GtkWidget *alignment3;
  GtkWidget *hbox3;
  GtkWidget *image3;
  GtkWidget *label3;
  GtkWidget *buttonRight;
  GtkWidget *alignment4;
  GtkWidget *hbox4;
  GtkWidget *image4;
  GtkWidget *label4;
  GtkWidget *buttonDown;
  GtkWidget *alignment2;
  GtkWidget *hbox2;
  GtkWidget *image2;
  GtkWidget *label2;
  GtkWidget *buttonUpLeft;
  GtkWidget *buttonUpRight;
  GtkWidget *buttonDownLeft;
  GtkWidget *buttonDownRight;
  GtkAccelGroup *accel_group;

  accel_group = gtk_accel_group_new ();

  MainWindow = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (MainWindow), _("AH Missile"));
  gtk_window_set_default_size (GTK_WINDOW (MainWindow), 300, 300);

  vbox1 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox1);
  gtk_container_add (GTK_CONTAINER (MainWindow), vbox1);

  menubar1 = gtk_menu_bar_new ();
  gtk_widget_show (menubar1);
  gtk_box_pack_start (GTK_BOX (vbox1), menubar1, FALSE, FALSE, 0);

  menuitem1 = gtk_menu_item_new_with_mnemonic (_("_File"));
  gtk_widget_show (menuitem1);
  gtk_container_add (GTK_CONTAINER (menubar1), menuitem1);

  menuitem1_menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem1), menuitem1_menu);

  quit1 = gtk_image_menu_item_new_from_stock ("gtk-quit", accel_group);
  gtk_widget_show (quit1);
  gtk_container_add (GTK_CONTAINER (menuitem1_menu), quit1);

  menuitem4 = gtk_menu_item_new_with_mnemonic (_("_Help"));
  gtk_widget_show (menuitem4);
  gtk_container_add (GTK_CONTAINER (menubar1), menuitem4);

  menuitem4_menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem4), menuitem4_menu);

  about1 = gtk_menu_item_new_with_mnemonic (_("_About"));
  gtk_widget_show (about1);
  gtk_container_add (GTK_CONTAINER (menuitem4_menu), about1);

  table1 = gtk_table_new (3, 3, FALSE);
  gtk_widget_show (table1);
  gtk_box_pack_start (GTK_BOX (vbox1), table1, TRUE, TRUE, 0);

  buttonUp = gtk_button_new ();
  gtk_widget_show (buttonUp);
  gtk_table_attach (GTK_TABLE (table1), buttonUp, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);

  alignment1 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment1);
  gtk_container_add (GTK_CONTAINER (buttonUp), alignment1);

  hbox1 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox1);
  gtk_container_add (GTK_CONTAINER (alignment1), hbox1);

  image1 = gtk_image_new_from_stock ("gtk-go-up", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image1);
  gtk_box_pack_start (GTK_BOX (hbox1), image1, FALSE, FALSE, 0);

  label1 = gtk_label_new_with_mnemonic (_("Up"));
  gtk_widget_show (label1);
  gtk_box_pack_start (GTK_BOX (hbox1), label1, FALSE, FALSE, 0);

  buttonLeft = gtk_button_new ();
  gtk_widget_show (buttonLeft);
  gtk_table_attach (GTK_TABLE (table1), buttonLeft, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);

  alignment5 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment5);
  gtk_container_add (GTK_CONTAINER (buttonLeft), alignment5);

  hbox5 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox5);
  gtk_container_add (GTK_CONTAINER (alignment5), hbox5);

  image5 = gtk_image_new_from_stock ("gtk-go-back", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image5);
  gtk_box_pack_start (GTK_BOX (hbox5), image5, FALSE, FALSE, 0);

  label5 = gtk_label_new_with_mnemonic (_("Left"));
  gtk_widget_show (label5);
  gtk_box_pack_start (GTK_BOX (hbox5), label5, FALSE, FALSE, 0);

  buttonFire = gtk_button_new ();
  gtk_widget_show (buttonFire);
  gtk_table_attach (GTK_TABLE (table1), buttonFire, 1, 2, 1, 2,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);

  alignment3 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment3);
  gtk_container_add (GTK_CONTAINER (buttonFire), alignment3);

  hbox3 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox3);
  gtk_container_add (GTK_CONTAINER (alignment3), hbox3);

  image3 = gtk_image_new_from_stock ("gtk-execute", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image3);
  gtk_box_pack_start (GTK_BOX (hbox3), image3, FALSE, FALSE, 0);

  label3 = gtk_label_new_with_mnemonic (_("Fire"));
  gtk_widget_show (label3);
  gtk_box_pack_start (GTK_BOX (hbox3), label3, FALSE, FALSE, 0);

  buttonRight = gtk_button_new ();
  gtk_widget_show (buttonRight);
  gtk_table_attach (GTK_TABLE (table1), buttonRight, 2, 3, 1, 2,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);

  alignment4 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment4);
  gtk_container_add (GTK_CONTAINER (buttonRight), alignment4);

  hbox4 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox4);
  gtk_container_add (GTK_CONTAINER (alignment4), hbox4);

  image4 = gtk_image_new_from_stock ("gtk-go-forward", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image4);
  gtk_box_pack_start (GTK_BOX (hbox4), image4, FALSE, FALSE, 0);

  label4 = gtk_label_new_with_mnemonic (_("Right"));
  gtk_widget_show (label4);
  gtk_box_pack_start (GTK_BOX (hbox4), label4, FALSE, FALSE, 0);

  buttonDown = gtk_button_new ();
  gtk_widget_show (buttonDown);
  gtk_table_attach (GTK_TABLE (table1), buttonDown, 1, 2, 2, 3,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL), 0, 0);

  alignment2 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment2);
  gtk_container_add (GTK_CONTAINER (buttonDown), alignment2);

  hbox2 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox2);
  gtk_container_add (GTK_CONTAINER (alignment2), hbox2);

  image2 = gtk_image_new_from_stock ("gtk-go-down", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image2);
  gtk_box_pack_start (GTK_BOX (hbox2), image2, FALSE, FALSE, 0);

  label2 = gtk_label_new_with_mnemonic (_("Down"));
  gtk_widget_show (label2);
  gtk_box_pack_start (GTK_BOX (hbox2), label2, FALSE, FALSE, 0);

  buttonUpLeft = gtk_button_new_with_mnemonic (_("Up/Left"));
  gtk_widget_show (buttonUpLeft);
  gtk_table_attach (GTK_TABLE (table1), buttonUpLeft, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_SHRINK | GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_SHRINK | GTK_FILL), 0, 0);

  buttonUpRight = gtk_button_new_with_mnemonic (_("Up/Right"));
  gtk_widget_show (buttonUpRight);
  gtk_table_attach (GTK_TABLE (table1), buttonUpRight, 2, 3, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_SHRINK | GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_SHRINK | GTK_FILL), 0, 0);

  buttonDownLeft = gtk_button_new_with_mnemonic (_("Down/Left"));
  gtk_widget_show (buttonDownLeft);
  gtk_table_attach (GTK_TABLE (table1), buttonDownLeft, 0, 1, 2, 3,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_SHRINK | GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_SHRINK | GTK_FILL), 0, 0);

  buttonDownRight = gtk_button_new_with_mnemonic (_("Down/Right"));
  gtk_widget_show (buttonDownRight);
  gtk_table_attach (GTK_TABLE (table1), buttonDownRight, 2, 3, 2, 3,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_SHRINK | GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND | GTK_SHRINK | GTK_FILL), 0, 0);

  g_signal_connect ((gpointer) MainWindow, "delete_event",
                    G_CALLBACK (on_MainWindow_delete_event),
                    NULL);
  g_signal_connect ((gpointer) MainWindow, "key_press_event",
                    G_CALLBACK (on_MainWindow_key_press_event),
                    NULL);
  g_signal_connect ((gpointer) MainWindow, "key_release_event",
                    G_CALLBACK (on_MainWindow_key_release_event),
                    NULL);
  g_signal_connect ((gpointer) quit1, "activate",
                    G_CALLBACK (on_quit1_activate),
                    NULL);
  g_signal_connect ((gpointer) about1, "activate",
                    G_CALLBACK (on_about1_activate),
                    NULL);
  g_signal_connect ((gpointer) buttonUp, "pressed",
                    G_CALLBACK (on_buttonUp_pressed),
                    NULL);
  g_signal_connect ((gpointer) buttonUp, "released",
                    G_CALLBACK (on_buttonUp_released),
                    NULL);
  g_signal_connect ((gpointer) buttonLeft, "pressed",
                    G_CALLBACK (on_buttonLeft_pressed),
                    NULL);
  g_signal_connect ((gpointer) buttonLeft, "released",
                    G_CALLBACK (on_buttonLeft_released),
                    NULL);
  g_signal_connect ((gpointer) buttonFire, "pressed",
                    G_CALLBACK (on_buttonFire_pressed),
                    NULL);
  g_signal_connect ((gpointer) buttonFire, "released",
                    G_CALLBACK (on_buttonFire_released),
                    NULL);
  g_signal_connect ((gpointer) buttonRight, "pressed",
                    G_CALLBACK (on_buttonRight_pressed),
                    NULL);
  g_signal_connect ((gpointer) buttonRight, "released",
                    G_CALLBACK (on_buttonRight_released),
                    NULL);
  g_signal_connect ((gpointer) buttonDown, "pressed",
                    G_CALLBACK (on_buttonDown_pressed),
                    NULL);
  g_signal_connect ((gpointer) buttonDown, "released",
                    G_CALLBACK (on_buttonDown_released),
                    NULL);
  g_signal_connect ((gpointer) buttonUpLeft, "pressed",
                    G_CALLBACK (on_buttonUpLeft_pressed),
                    NULL);
  g_signal_connect ((gpointer) buttonUpLeft, "released",
                    G_CALLBACK (on_buttonUpLeft_released),
                    NULL);
  g_signal_connect ((gpointer) buttonUpRight, "pressed",
                    G_CALLBACK (on_buttonUpRight_pressed),
                    NULL);
  g_signal_connect ((gpointer) buttonUpRight, "released",
                    G_CALLBACK (on_buttonUpRight_released),
                    NULL);
  g_signal_connect ((gpointer) buttonDownLeft, "pressed",
                    G_CALLBACK (on_buttonDownLeft_pressed),
                    NULL);
  g_signal_connect ((gpointer) buttonDownLeft, "released",
                    G_CALLBACK (on_buttonDownLeft_released),
                    NULL);
  g_signal_connect ((gpointer) buttonDownRight, "pressed",
                    G_CALLBACK (on_buttonDownRight_pressed),
                    NULL);
  g_signal_connect ((gpointer) buttonDownRight, "released",
                    G_CALLBACK (on_buttonDownRight_released),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (MainWindow, MainWindow, "MainWindow");
  GLADE_HOOKUP_OBJECT (MainWindow, vbox1, "vbox1");
  GLADE_HOOKUP_OBJECT (MainWindow, menubar1, "menubar1");
  GLADE_HOOKUP_OBJECT (MainWindow, menuitem1, "menuitem1");
  GLADE_HOOKUP_OBJECT (MainWindow, menuitem1_menu, "menuitem1_menu");
  GLADE_HOOKUP_OBJECT (MainWindow, quit1, "quit1");
  GLADE_HOOKUP_OBJECT (MainWindow, menuitem4, "menuitem4");
  GLADE_HOOKUP_OBJECT (MainWindow, menuitem4_menu, "menuitem4_menu");
  GLADE_HOOKUP_OBJECT (MainWindow, about1, "about1");
  GLADE_HOOKUP_OBJECT (MainWindow, table1, "table1");
  GLADE_HOOKUP_OBJECT (MainWindow, buttonUp, "buttonUp");
  GLADE_HOOKUP_OBJECT (MainWindow, alignment1, "alignment1");
  GLADE_HOOKUP_OBJECT (MainWindow, hbox1, "hbox1");
  GLADE_HOOKUP_OBJECT (MainWindow, image1, "image1");
  GLADE_HOOKUP_OBJECT (MainWindow, label1, "label1");
  GLADE_HOOKUP_OBJECT (MainWindow, buttonLeft, "buttonLeft");
  GLADE_HOOKUP_OBJECT (MainWindow, alignment5, "alignment5");
  GLADE_HOOKUP_OBJECT (MainWindow, hbox5, "hbox5");
  GLADE_HOOKUP_OBJECT (MainWindow, image5, "image5");
  GLADE_HOOKUP_OBJECT (MainWindow, label5, "label5");
  GLADE_HOOKUP_OBJECT (MainWindow, buttonFire, "buttonFire");
  GLADE_HOOKUP_OBJECT (MainWindow, alignment3, "alignment3");
  GLADE_HOOKUP_OBJECT (MainWindow, hbox3, "hbox3");
  GLADE_HOOKUP_OBJECT (MainWindow, image3, "image3");
  GLADE_HOOKUP_OBJECT (MainWindow, label3, "label3");
  GLADE_HOOKUP_OBJECT (MainWindow, buttonRight, "buttonRight");
  GLADE_HOOKUP_OBJECT (MainWindow, alignment4, "alignment4");
  GLADE_HOOKUP_OBJECT (MainWindow, hbox4, "hbox4");
  GLADE_HOOKUP_OBJECT (MainWindow, image4, "image4");
  GLADE_HOOKUP_OBJECT (MainWindow, label4, "label4");
  GLADE_HOOKUP_OBJECT (MainWindow, buttonDown, "buttonDown");
  GLADE_HOOKUP_OBJECT (MainWindow, alignment2, "alignment2");
  GLADE_HOOKUP_OBJECT (MainWindow, hbox2, "hbox2");
  GLADE_HOOKUP_OBJECT (MainWindow, image2, "image2");
  GLADE_HOOKUP_OBJECT (MainWindow, label2, "label2");
  GLADE_HOOKUP_OBJECT (MainWindow, buttonUpLeft, "buttonUpLeft");
  GLADE_HOOKUP_OBJECT (MainWindow, buttonUpRight, "buttonUpRight");
  GLADE_HOOKUP_OBJECT (MainWindow, buttonDownLeft, "buttonDownLeft");
  GLADE_HOOKUP_OBJECT (MainWindow, buttonDownRight, "buttonDownRight");

  gtk_window_add_accel_group (GTK_WINDOW (MainWindow), accel_group);

  return MainWindow;
}

GtkWidget*
create_NoDevDlg (void)
{
  GtkWidget *NoDevDlg;
  GtkWidget *vbox2;
  GtkWidget *labelErrHeader;
  GtkWidget *labelNoDevErrMsg;
  GtkWidget *hbuttonbox1;
  GtkWidget *button1;

  NoDevDlg = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (NoDevDlg), _("AH Missile - Error no device found"));
  gtk_window_set_position (GTK_WINDOW (NoDevDlg), GTK_WIN_POS_CENTER);
  gtk_window_set_modal (GTK_WINDOW (NoDevDlg), TRUE);
  gtk_window_set_default_size (GTK_WINDOW (NoDevDlg), 300, 200);
  gtk_window_set_type_hint (GTK_WINDOW (NoDevDlg), GDK_WINDOW_TYPE_HINT_DIALOG);

  vbox2 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox2);
  gtk_container_add (GTK_CONTAINER (NoDevDlg), vbox2);

  labelErrHeader = gtk_label_new (_("<span size=\"xx-large\" foreground=\"red\">Error!</span>"));
  gtk_widget_show (labelErrHeader);
  gtk_box_pack_start (GTK_BOX (vbox2), labelErrHeader, TRUE, TRUE, 0);
  gtk_label_set_use_markup (GTK_LABEL (labelErrHeader), TRUE);
  gtk_label_set_justify (GTK_LABEL (labelErrHeader), GTK_JUSTIFY_CENTER);
  gtk_label_set_single_line_mode (GTK_LABEL (labelErrHeader), TRUE);

  labelNoDevErrMsg = gtk_label_new (_("Could not find/grab the usb device. Please make sure the Missile Launcher is properly plugged in before starting this program."));
  gtk_widget_show (labelNoDevErrMsg);
  gtk_box_pack_start (GTK_BOX (vbox2), labelNoDevErrMsg, TRUE, TRUE, 0);
  gtk_label_set_justify (GTK_LABEL (labelNoDevErrMsg), GTK_JUSTIFY_CENTER);
  gtk_label_set_line_wrap (GTK_LABEL (labelNoDevErrMsg), TRUE);
  gtk_misc_set_padding (GTK_MISC (labelNoDevErrMsg), 20, 0);

  hbuttonbox1 = gtk_hbutton_box_new ();
  gtk_widget_show (hbuttonbox1);
  gtk_box_pack_end (GTK_BOX (vbox2), hbuttonbox1, FALSE, FALSE, 0);
  gtk_button_box_set_layout (GTK_BUTTON_BOX (hbuttonbox1), GTK_BUTTONBOX_END);

  button1 = gtk_button_new_from_stock ("gtk-quit");
  gtk_widget_show (button1);
  gtk_container_add (GTK_CONTAINER (hbuttonbox1), button1);
  GTK_WIDGET_SET_FLAGS (button1, GTK_CAN_DEFAULT);

  g_signal_connect ((gpointer) NoDevDlg, "delete_event",
                    G_CALLBACK (on_NoDevDlg_delete_event),
                    NULL);
  g_signal_connect ((gpointer) button1, "clicked",
                    G_CALLBACK (on_buttonQuit_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (NoDevDlg, NoDevDlg, "NoDevDlg");
  GLADE_HOOKUP_OBJECT (NoDevDlg, vbox2, "vbox2");
  GLADE_HOOKUP_OBJECT (NoDevDlg, labelErrHeader, "labelErrHeader");
  GLADE_HOOKUP_OBJECT (NoDevDlg, labelNoDevErrMsg, "labelNoDevErrMsg");
  GLADE_HOOKUP_OBJECT (NoDevDlg, hbuttonbox1, "hbuttonbox1");
  GLADE_HOOKUP_OBJECT (NoDevDlg, button1, "button1");

  return NoDevDlg;
}
