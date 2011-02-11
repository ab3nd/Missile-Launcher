#include <gtk/gtk.h>


void
on_quit1_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_about1_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_buttonUp_pressed                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonUp_released                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonLeft_pressed                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonLeft_released                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonFire_pressed                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonFire_released                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonRight_pressed                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonRight_released                (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonDown_pressed                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonDown_released                 (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_MainWindow_delete_event             (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

gboolean
on_MainWindow_button_press_event       (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

gboolean
on_MainWindow_button_release_event     (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

gboolean
on_MainWindow_key_press_event          (GtkWidget       *widget,
                                        GdkEventKey     *event,
                                        gpointer         user_data);

gboolean
on_MainWindow_key_release_event        (GtkWidget       *widget,
                                        GdkEventKey     *event,
                                        gpointer         user_data);

gboolean
on_NoDevDlg_delete_event               (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

void
on_buttonQuit_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonUpLeft_pressed                (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonUpLeft_released               (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonUpRight_pressed               (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonUpRight_released              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonDownLeft_pressed              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonDownLeft_released             (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonDownRight_pressed             (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonDownRight_released            (GtkButton       *button,
                                        gpointer         user_data);
