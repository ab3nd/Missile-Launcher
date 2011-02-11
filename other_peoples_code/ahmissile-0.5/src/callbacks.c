#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>

#include <stdlib.h> /* exit */

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#include "ahmissile.h"


void
on_quit1_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
	ahmissile_quit();
}


void
on_about1_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
	ahmissile_about();
}


void
on_buttonUp_pressed                    (GtkButton       *button,
                                        gpointer         user_data)
{
	ahmissile_control_up();
}


void
on_buttonUp_released                   (GtkButton       *button,
                                        gpointer         user_data)
{
	ahmissile_control_stop();
}


void
on_buttonLeft_pressed                  (GtkButton       *button,
                                        gpointer         user_data)
{
	ahmissile_control_left();
}


void
on_buttonLeft_released                 (GtkButton       *button,
                                        gpointer         user_data)
{
	ahmissile_control_stop();
}


void
on_buttonFire_pressed                  (GtkButton       *button,
                                        gpointer         user_data)
{
	ahmissile_control_fire();
}


void
on_buttonFire_released                 (GtkButton       *button,
                                        gpointer         user_data)
{
	/* fire command is auto-stopped */
}


void
on_buttonRight_pressed                 (GtkButton       *button,
                                        gpointer         user_data)
{
	ahmissile_control_right();
}


void
on_buttonRight_released                (GtkButton       *button,
                                        gpointer         user_data)
{
	ahmissile_control_stop();
}


void
on_buttonDown_pressed                  (GtkButton       *button,
                                        gpointer         user_data)
{
	ahmissile_control_down();
}


void
on_buttonDown_released                 (GtkButton       *button,
                                        gpointer         user_data)
{
	ahmissile_control_stop();
}


gboolean
on_MainWindow_delete_event             (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data)
{
	ahmissile_quit();
	return FALSE;
}

gboolean
on_MainWindow_key_press_event          (GtkWidget       *widget,
                                        GdkEventKey     *event,
                                        gpointer         user_data)
{
	GdkEventKey *key = (GdkEventKey*)event;

	switch (key->keyval) {
	case GDK_Up:
	case GDK_KP_Up:
	case GDK_KP_8:
		ahmissile_control_up();
	break;

	case GDK_Down:
	case GDK_KP_Down:
	case GDK_KP_2:
		ahmissile_control_down();
	break;

	case GDK_Left:
	case GDK_KP_Left:
	case GDK_KP_4:
		ahmissile_control_left();
	break;

	case GDK_Right:
	case GDK_KP_Right:
	case GDK_KP_6:
		ahmissile_control_right();
	break;

	case GDK_KP_Begin:
	case GDK_KP_5:
		ahmissile_control_fire();
	break;

	case GDK_KP_Home:
	case GDK_KP_7:
		ahmissile_control_upleft();
	break;

	case GDK_KP_Page_Up:
	case GDK_KP_9:
		ahmissile_control_upright();
	break;

	case GDK_KP_End:
	case GDK_KP_1:
		ahmissile_control_downleft();
	break;

	case GDK_KP_Page_Down:
	case GDK_KP_3:
		ahmissile_control_downright();
	break;

	default:
		fprintf(stderr, "WARN: unknown key pressed (0x%x)...\n",
				key->keyval);
	break;
	}

	return FALSE;
}


gboolean
on_MainWindow_key_release_event        (GtkWidget       *widget,
                                        GdkEventKey     *event,
                                        gpointer         user_data)
{
	ahmissile_control_stop();
	return FALSE;
}


gboolean
on_NoDevDlg_delete_event               (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data)
{
	exit(-1);
	return FALSE;
}


void
on_buttonQuit_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
	exit(-1);
}


void
on_buttonUpLeft_pressed                (GtkButton       *button,
                                        gpointer         user_data)
{
	ahmissile_control_upleft();
}


void
on_buttonUpLeft_released               (GtkButton       *button,
                                        gpointer         user_data)
{
	ahmissile_control_stop();
}


void
on_buttonUpRight_pressed               (GtkButton       *button,
                                        gpointer         user_data)
{
	ahmissile_control_upright();
}


void
on_buttonUpRight_released              (GtkButton       *button,
                                        gpointer         user_data)
{
	ahmissile_control_stop();
}


void
on_buttonDownLeft_pressed              (GtkButton       *button,
                                        gpointer         user_data)
{
	ahmissile_control_downleft();
}


void
on_buttonDownLeft_released             (GtkButton       *button,
                                        gpointer         user_data)
{
	ahmissile_control_stop();
}


void
on_buttonDownRight_pressed             (GtkButton       *button,
                                        gpointer         user_data)
{
	ahmissile_control_downright();
}


void
on_buttonDownRight_released            (GtkButton       *button,
                                        gpointer         user_data)
{
	ahmissile_control_stop();
}

