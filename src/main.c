/*
 * Copyright (C) 2013 John Goodland <zaniah@users.sourceforge.net>;
 *					VERSION 1.03
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 * -----------------------------------------------------------------------------
 *
 * Compile for WINDOWS using:
 * gcc -Wall -g main.c -lws2_32 -o gemwest.exe `pkg-config --cflags --libs gtk+-2.0` --mms-bitfields -mwindows
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <gtk/gtk.h>
#include <string.h>
#include <math.h>
#include "header.h"

#ifndef WIN32
#include <gconf/gconf-client.h> /*GConf for Linux only*/
#endif

#if XML2FILE
#include "glade_file.c"
#endif
//const gchar *initStatusBarMess="Leave Gem Stone and Cut fields empty for Round Brilliant Diamond";
const gchar *MinitStatusBarMess=INITSTATUSBARMESS;
const gchar *icon;
gint result;
static void destroy( GtkWidget *widget,
		gpointer data )
{
	/*g_print("program terminated\n");*/
	gtk_main_quit ();
}
int main (int argc, char *argv[])
{
	gtk_init (&argc, &argv);
#ifndef WIN32
	gconf_init(argc, argv, NULL);
#endif
	g = g_slice_new (Content);
	GtkBuilder *builder;
	/********************************************************************/
#ifdef unix
	icon = ICON_SOURCE;
	if (g_file_test(icon, G_FILE_TEST_EXISTS))
	{
		gtk_window_set_default_icon_from_file(ICON_SOURCE, NULL);
	}else {
		gtk_window_set_default_icon_from_file(PACKAGE_DATA_DIR "/" ICON_SOURCE, NULL);
		/*icon = g_file_test(ICON_SOURCE, G_FILE_TEST_EXISTS) ? ICON_SOURCE : ICON_PACKAGE;*/
	}
	gtk_window_set_default_icon_from_file(icon, NULL);
	builder = gtk_builder_new ();
	if(XML2FILE==TRUE){/*xml file is compiled directly into executable*/
		gtk_builder_add_from_string(builder, my_glade_file, -1, NULL);
	}else{/*default: program loads xml glade file at run time*/
		result = gtk_builder_add_from_file(builder, BUILDER_XML_FILE, NULL) || gtk_builder_add_from_file(builder, PACKAGE_DATA_DIR "/" PACKAGE "/" BUILDER_XML_FILE, NULL);
		//result = gtk_builder_add_from_file (builder, BUILDER_XML_FILE, NULL);
	}/*default: program loads xml glade file at run time*/
	if(!result){
		g_print ("glade/xml file not found!\nI looked in %s/%s/%s",PACKAGE_DATA_DIR,PACKAGE,BUILDER_XML_FILE);		
	}
#endif
#ifdef WIN32

	icon = ICON_SOURCE;
	/*icon = g_file_test(ICON_SOURCE, G_FILE_TEST_EXISTS) ? ICON_SOURCE : ICON_PACKAGE;*/
	gtk_window_set_default_icon_from_file(icon, NULL);
	builder = gtk_builder_new ();
	if(XML2FILE==TRUE){/*xml file is compiled directly into executable*/
		gtk_builder_add_from_string(builder, my_glade_file, -1, NULL);
	}else{/*default: program loads xml glade file at run time*/
		gtk_builder_add_from_file (builder, BUILDER_XML_FILE, NULL);
	}/* END WHETHER TO LOAD glade file from file or string*/

#endif
	g->window = GTK_WIDGET (gtk_builder_get_object (builder, "window"));
	g->entryl = GTK_WIDGET (gtk_builder_get_object (builder, "entryl"));
	g->entryw = GTK_WIDGET (gtk_builder_get_object (builder, "entryw"));
	g->entryd = GTK_WIDGET (gtk_builder_get_object (builder, "entryd"));
	g->entrys = GTK_WIDGET (gtk_builder_get_object (builder, "entrys"));
	g->entryf = GTK_WIDGET (gtk_builder_get_object (builder, "entryf"));
	g->entryb = GTK_WIDGET (gtk_builder_get_object (builder, "entryb"));
	g->entryBdialog = GTK_WIDGET (gtk_builder_get_object (builder, "entryBdialog"));
	g->entryGEM = GTK_WIDGET (gtk_builder_get_object (builder, "entryGEM"));
	g->entryCUT= GTK_WIDGET (gtk_builder_get_object (builder, "entryCUT"));
	g->spinbuttonGIR = GTK_WIDGET (gtk_builder_get_object (builder, "spinbuttonGIR"));
	g->spinbuttonPAV = GTK_WIDGET (gtk_builder_get_object (builder, "spinbuttonPAV"));
	g->spinbuttonSHP = GTK_WIDGET (gtk_builder_get_object (builder, "spinbuttonSHP"));
	g->entryPrefThresh = GTK_WIDGET (gtk_builder_get_object (builder, "entryPrefThresh"));
	g->hboxZ = GTK_WIDGET (gtk_builder_get_object (builder, "hboxZ"));
	g->hboxCUT_PLATE = GTK_WIDGET (gtk_builder_get_object (builder, "hboxCUT_PLATE"));
	g->hboxCUT_IMAGE = GTK_WIDGET (gtk_builder_get_object (builder, "hboxCUT_IMAGE"));
	g->hboxGEM_IMAGE = GTK_WIDGET (gtk_builder_get_object (builder, "hboxGEM_IMAGE"));
	g->hboxDP_IMAGE = GTK_WIDGET (gtk_builder_get_object (builder, "hboxDP_IMAGE"));
	g->hboxT = GTK_WIDGET (gtk_builder_get_object (builder, "hboxT"));
	g->hboxRB0 = GTK_WIDGET (gtk_builder_get_object (builder, "hboxRB0"));
	g->hboxRB1 = GTK_WIDGET (gtk_builder_get_object (builder, "hboxRB1"));
	g->hboxRB2 = GTK_WIDGET (gtk_builder_get_object (builder, "hboxRB2"));
	g->hboxRB3 = GTK_WIDGET (gtk_builder_get_object (builder, "hboxRB3"));
	g->hboxRecutLegend = GTK_WIDGET (gtk_builder_get_object (builder, "hboxRecutLegend"));
	g->hboxRecutContainer = GTK_WIDGET (gtk_builder_get_object (builder, "hboxRecutContainer"));
	g->labelRecutLabelling = GTK_WIDGET (gtk_builder_get_object (builder, "labelRecutLabelling"));
	g->hboxURILV = GTK_WIDGET (gtk_builder_get_object (builder, "hboxURILV"));
	g->hboxWebsite = GTK_WIDGET (gtk_builder_get_object (builder, "hboxWebsite"));
	g->vboxLOG = GTK_WIDGET (gtk_builder_get_object (builder, "vboxLOG"));
	g->CBclear_log = GTK_WIDGET (gtk_builder_get_object (builder, "CBclear_log"));
	g->confirmDeleteLog = GTK_WIDGET (gtk_builder_get_object (builder, "confirmDeleteLog"));
	g->buttonCloseLog = GTK_WIDGET (gtk_builder_get_object (builder, "buttonCloseLog"));
	g->logPREF = GTK_WIDGET (gtk_builder_get_object (builder, "logPREF"));
	g->vboxRecut = GTK_WIDGET (gtk_builder_get_object (builder, "vboxRecut"));
	g->vboxIMAGEcont = GTK_WIDGET (gtk_builder_get_object (builder, "vboxIMAGEcont"));
	g->drawingarea1 = GTK_WIDGET (gtk_builder_get_object (builder, "drawingarea1"));
	g->imageDEF = GTK_WIDGET (gtk_builder_get_object (builder, "imageDEF"));
	g->interpolateCB= GTK_WIDGET (gtk_builder_get_object (builder, "interpolateCB"));
	g->manoverideFCB= GTK_WIDGET (gtk_builder_get_object (builder, "manoverideFCB"));
	g->labelFA = GTK_WIDGET (gtk_builder_get_object (builder, "labelFA"));
	g->labelGEMsel= GTK_WIDGET (gtk_builder_get_object (builder, "labelGEMsel"));
	g->labelCUTsel= GTK_WIDGET (gtk_builder_get_object (builder, "labelCUTsel"));
	g->labelLW= GTK_WIDGET (gtk_builder_get_object (builder, "labelLW"));
	g->labelLeqW= GTK_WIDGET (gtk_builder_get_object (builder, "labelLeqW"));
	g->labell= GTK_WIDGET (gtk_builder_get_object (builder, "labell"));
	g->labelw= GTK_WIDGET (gtk_builder_get_object (builder, "labelw"));
	g->labelFactor= GTK_WIDGET (gtk_builder_get_object (builder, "labelFactor"));
	g->labelDP= GTK_WIDGET (gtk_builder_get_object (builder, "labelDP"));
	g->labelLogPath= GTK_WIDGET (gtk_builder_get_object (builder, "labelLogPath"));
	g->answer = GTK_WIDGET (gtk_builder_get_object (builder, "answer"));
	g->answerRecut = GTK_WIDGET (gtk_builder_get_object (builder, "answerRecut"));
	g->calculateB = GTK_WIDGET (gtk_builder_get_object (builder, "calculateB"));
	g->buttonLEQW = GTK_WIDGET (gtk_builder_get_object (builder, "buttonLEQW"));
	g->buttonADJ = GTK_WIDGET (gtk_builder_get_object (builder, "buttonADJ"));
	g->clearGB = GTK_WIDGET (gtk_builder_get_object (builder, "clearGB"));
	g->clearCB = GTK_WIDGET (gtk_builder_get_object (builder, "clearCB"));
	g->CBDecPlace = GTK_WIDGET (gtk_builder_get_object (builder, "CBDecPlace"));
	g->CBRecut = GTK_WIDGET (gtk_builder_get_object (builder, "CBRecut"));
	g->CBEnablLogging = GTK_WIDGET (gtk_builder_get_object (builder, "CBEnablLogging"));
	g->resetB = GTK_WIDGET (gtk_builder_get_object (builder, "resetB"));
	g->statusbar = GTK_WIDGET (gtk_builder_get_object (builder,"statusbar"));
	g->aboutdialog = GTK_WIDGET (gtk_builder_get_object (builder,"aboutdialog"));
	g->linkbutton1 = GTK_WIDGET (gtk_builder_get_object (builder,"linkbutton1"));
	g->dialogH = GTK_WIDGET (gtk_builder_get_object (builder,"dialogH"));
	g->dialogPREF = GTK_WIDGET (gtk_builder_get_object (builder,"dialogPREF"));
	g->statusbar = GTK_WIDGET (gtk_builder_get_object (builder,"statusbar"));
	g->context_id = gtk_statusbar_get_context_id(GTK_STATUSBAR (g->statusbar ), PROGRAM_NAME);
	g->statusbar_context_id = g->context_id;
	g->text_view = GTK_WIDGET (gtk_builder_get_object (builder,"text_view"));
	/********************************************************************/
	loadPreferences();/* Load saved preferences from a previous session*/
	listGemCompletion();/* Lists all GEMS in database alphabetically on user entry*/
	/********************************************************************/
	toggleEntryEditable(g->entrys,FALSE);/*make SG uneditable as default*/
	g_signal_connect (g->window, "destroy",G_CALLBACK (destroy), NULL);
	/****For WINDOWS ACTIVATE Window Manager Close Button*****/ 
	#ifdef WIN32
	gtk_window_set_deletable(GTK_WINDOW(g->aboutdialog),TRUE);
	gtk_window_set_deletable(GTK_WINDOW(g->logPREF),TRUE);
    gtk_window_set_deletable(GTK_WINDOW(g->dialogH),TRUE);
	gtk_window_set_deletable(GTK_WINDOW(g->dialogPREF),TRUE);
	#endif
	g_signal_connect (g->manoverideFCB, "toggled",G_CALLBACK (toggleEditableFactor),NULL);
	g_signal_connect (g->entryGEM, "insert-text",G_CALLBACK (writetoSG),NULL);
	/**********************New in 1.03 prevent Window Manager [x] from deleting Window************/
	g_signal_connect (g->aboutdialog, "delete-event", G_CALLBACK (gtk_widget_hide_on_delete), NULL);
	g_signal_connect (g->logPREF, "delete-event", G_CALLBACK (gtk_widget_hide_on_delete), NULL);
	g_signal_connect (g->dialogH, "delete-event", G_CALLBACK (gtk_widget_hide_on_delete), NULL);
	g_signal_connect (g->dialogPREF, "delete-event", G_CALLBACK (gtk_widget_hide_on_delete), NULL);
		/********************************************************************/
	gtk_builder_connect_signals (builder, NULL);
	g_object_unref (G_OBJECT (builder));
	gtk_widget_show (g->window);
	/*make_toggles();set up the default toggle buttons for either diamond or a gemstone*/
	print_ADJUST_XPM();/*print the adjustment icon*/
	make_radios();
	make_url2Website(WEBSITEBASE,WEBSITEURL,g->hboxWebsite,pwebURI);/*manually make URL to website in aboutdialog regular*/ 
	make_url2Website(URILVSTRING,URILV,g->hboxURILV,pwebURI);
	/*manually make URL to website in aboutdialog regular gtk_about_dialog_get_website(..)*/
	gtk_widget_hide(GTK_WIDGET(g->vboxRecut));
	listCutCompletion();/* Lists all CUTS in database alphabetically on user entry*/
	gtk_label_set_markup(GTK_LABEL (g->labelCUTsel), FIRSTRUNDEFDIACUTLABELMESS);/*set default CUT label text*/
	gtk_entry_set_text(GTK_ENTRY (g->entryf), DEFDIAFACTORT);/*set default values for a round brilliant*/
	gtk_entry_set_text(GTK_ENTRY (g->entryCUT), DIAROUND);/*set default values for a round brilliant*/
	/********************************************************************/
	g->delsbid=gtk_statusbar_push (GTK_STATUSBAR (g->statusbar ), GPOINTER_TO_INT (g->context_id), MinitStatusBarMess);
	gtk_main ();
	g_slice_free (Content, g);
	return 0;
}

