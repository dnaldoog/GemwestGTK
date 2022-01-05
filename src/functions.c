/********************************
 *
 * 
 * 
 * FUNCTIONS 1.03
 * 
 * 
 * 
 *******************************/
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <glib.h>
#include <gio/gio.h>
#include <glib/gstdio.h>
#include <unistd.h>
//~ #include <conio.h>
#ifdef WIN32 
#include <windows.h>
#include <winsock2.h>
#include <Ws2tcpip.h>
#include <wspiapi.h>
#include <process.h>
#else
#include <gconf/gconf-client.h>
#endif
#include "header.h"
#include "functions.h"
#include "pixmaps_c.h"
#include "pixmaps_s.h"
/**************************************************
 * 
 * CALLBACK FUNCTIONS
 * 
 **************************************************/
void on_MlLog_activate_item(GtkWidget *widget,gpointer data ){
	//g_print("%s triggered on line %d\n",__FUNCTION__,__LINE__);
	if(gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON (g->CBEnablLogging))==TRUE){	
		gtk_window_present(GTK_WINDOW(g->logPREF));
		display_log();//if(gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON (g->CBEnablLogging))==TRUE){	
	}//on_MlLog_activate_item 
	else{
		info_message("Logging is disabled\nEnable in Preferences");
	}
}/*END FUNCTION : */
/********************************************************************/
void on_buttonCloseLog_clicked(GtkWidget *widget,gpointer data ){
	gchar *status;
	status = g_strdup_printf ("Ready");
	g->delsbid=gtk_statusbar_push (GTK_STATUSBAR (g->statusbar),
			GPOINTER_TO_INT (g->context_id), status);
	g_free(status);
}/*END FUNCTION : */
/********************************************************************/ 
void on_buttonDELLOG_clicked(GtkWidget *widget,gpointer data ){
	gchar *status = g_strdup_printf("Log File Contents cleared!");
	clear_log_file(LOGPATH);
	g->delsbid=gtk_statusbar_push (GTK_STATUSBAR (g->statusbar),
			GPOINTER_TO_INT (g->context_id), status);
	g_free(status);
}/*END FUNCTION : */
/********************************************************************/ 
void on_CBclear_log_clicked(GtkWidget *widget,gpointer data )
{
	gtk_window_present(GTK_WINDOW(g->confirmDeleteLog));
}/*END FUNCTION : */
/********************************************************************/ 
void on_CBEnablLogging_toggled(GtkWidget *widget,gpointer data){
#ifndef WIN32
	gboolean enabLog=toggle_button_callback(g->CBEnablLogging,NULL);
	GConfClient *config;
	/*******************SET GCONF*******************************/
	config = gconf_client_get_default ();
	gconf_client_set_bool (config, "/apps/gemwest/enablelogging", enabLog, NULL);
#endif
}/*END FUNCTION : */
/********************************************************************/
void on_buttonCopy2C (GtkWidget *widget, gpointer data)
{
	gchar *message;
	GError *err=NULL;
	g_file_get_contents (LOGPATH, &message, NULL, &err);
	gtk_clipboard_set_text(gtk_clipboard_get(GDK_SELECTION_CLIPBOARD), message, strlen(message));
	/* store the clipboard text */
	gtk_clipboard_store(gtk_clipboard_get(GDK_SELECTION_CLIPBOARD));
}/*END FUNCTION : */
/********************************************************************/
void on_CBRecut_toggled(GtkWidget *widget, gpointer data) {
#ifdef unix
	GConfClient *config;
	gboolean setStateRecutOn=toggle_button_callback(g->CBRecut,NULL);
	/*******************SET GCONF*******************************/
	config = gconf_client_get_default ();
	gconf_client_set_bool (config, "/apps/gemwest/showrecut", setStateRecutOn, NULL);
	if(setStateRecutOn==FALSE)logRW=NULL;
	/*this clears the recut data from being printed to log*/
#endif
}/*END FUNCTION : */
/********************************************************************/
void on_CBDecPlace_toggled(GtkWidget *widget, gpointer data) {
#ifdef unix
	GConfClient *config;
	gboolean setStateShowThou=toggle_button_callback(g->CBDecPlace,NULL);
	/*******************SET GCONF*******************************/
	config = gconf_client_get_default ();
	gconf_client_set_bool (config, "/apps/gemwest/showthou", setStateShowThou, NULL);
#endif
}/*END FUNCTION : */
/********************************************************************/
void on_entryPrefThresh_changed(GtkWidget *widget, gpointer data) {
#ifdef unix
	GConfClient *config;
	const gchar* setStateEntryPrefThresh=gtk_entry_get_text(GTK_ENTRY(g->entryPrefThresh));
	/************************SET GCONF*******************************/
	config = gconf_client_get_default ();
	gconf_client_set_string (config, "/apps/gemwest/setthouthresh", setStateEntryPrefThresh, NULL);
#endif
}/*END FUNCTION : */
/********************************************************************/
void radio_gemdia_sel_call_back( GtkRadioButton *rb )
{
	if( gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON( rb ) ) ){
		gateway2_GEM();
	}else{
		gateway2_DIA();
	}
	listCutCompletion();/*cut set will be changed from here*/
}/*END FUNCTION : radio_gemdia_sel_call_back( GtkButton *b, GtkRadioButton *rb )*/
/********************************************************************/
void on_help_show(GtkWidget *widget,gpointer data){
	/*place_Cut_Legend_in_help_file();disabled to reduce space*/
	/*places embedded cut legend graphic in help file preloaded in main*/
}/*END FUNCTION : */
/********************************************************************/
void on_aboutdialog_show(GtkWidget *widget,gpointer data){
	/* GtkWidget is the storage type for widgets */
	/* now for the pixmap from gdk */
	style_a = gtk_widget_get_style( g->aboutdialog );
	pixmap_a = gdk_pixmap_create_from_xpm_d( g->aboutdialog->window, &mask_a,
			&style_a->bg[GTK_STATE_NORMAL],
			(gchar **)ZaniahLogoDotXPM );
	/* a pixmap widget to contain the pixmap */
	pixmapwid_a = gtk_image_new_from_pixmap( pixmap_a, mask_a );
	tooltip(GTK_WIDGET(pixmapwid_a),"Software by Zaniah");
	gtk_widget_show( pixmapwid_a );
	if(countPixmapZLogo==1)gtk_box_pack_start (GTK_BOX (g->hboxZ), pixmapwid_a, FALSE, FALSE, 0);
	countPixmapZLogo++;/*variable in pixmaps_c.h*/
	g_object_unref(pixmap_a);
	g_object_unref(mask_a);
}/*END FUNCTION : */
/********************************************************************/
void on_calculateB_clicked (GtkWidget *widget, gpointer data)
{
	Calculate(g->calculateB,NULL);/*calls the calculate function*/
}/*END FUNCTION : */
/********************************************************************/
void on_resetB_clicked(GtkWidget *widget,gpointer data)
{
	const gchar *GemLabel=DEFAULTDIALABELMESS;
	gtk_label_set_markup(GTK_LABEL (g->labelGEMsel), GemLabel);
	const gchar *CutLabel=FIRSTRUNDEFDIACUTLABELMESS;
	gtk_label_set_markup(GTK_LABEL (g->labelCUTsel), CutLabel);
	gtk_label_set_text (GTK_LABEL(g->answer), "");
	gtk_entry_set_text(GTK_ENTRY(g->entryl), "");
	gtk_entry_set_text(GTK_ENTRY(g->entryw), "");
	gtk_entry_set_text(GTK_ENTRY(g->entryd), "");
	gtk_entry_set_text(GTK_ENTRY(g->entrys), "");
	gtk_entry_set_text(GTK_ENTRY(g->entryb), "");
	gtk_entry_set_text(GTK_ENTRY(g->entryf), DEFDIAFACTORT);
	gtk_label_set_text(GTK_LABEL(g->labelFA), "");
	gtk_label_set_text(GTK_LABEL(g->answerRecut), "");
	resetDIA();
	gtk_label_set_text(GTK_LABEL(g->labelLW), "L:W Ratio:");
	gtk_label_set_text(GTK_LABEL(g->labelDP), "Depth%:");
	showImageFields(FALSE);
	g->delsbid=gtk_statusbar_push (GTK_STATUSBAR (g->statusbar ), GPOINTER_TO_INT (data), initStatusBarMess);
	toggleEntryEditable(g->entrys,FALSE);/*make SG uneditable*/
	print_RECUTIMAGE_PIX(noimage_c," "," ");/*reset recut image*/
	gtk_widget_hide(g->vboxRecut);/*hide recut fields*/
	gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON (g->manoverideFCB),FALSE);/*unset manoveride button*/
	gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON (g->interpolateCB),FALSE);/*unset interpolate button*/
}/*END FUNCTION : */
/********************************************************************/
void on_entryGEM_insert_text(GtkWidget *widget,gpointer data){
}/*END FUNCTION : */
/********************************************************************/
void on_clearCB_clicked(GtkWidget *widget,gpointer data){
	gtk_entry_set_text(GTK_ENTRY(g->entryCUT), "");
	gtk_entry_set_text(GTK_ENTRY(g->entryf), "");
}/*END FUNCTION : */
/********************************************************************/
void on_clearGB_clicked(GtkWidget *widget,gpointer data){
	gtk_entry_set_text(GTK_ENTRY(g->entryGEM), "");
	gtk_entry_set_text(GTK_ENTRY(g->entrys), "");
	print_GEM_IMAGE_PIX(noimage_c);
}/*END FUNCTION : */
/********************************************************************/
void on_buttonLEQW_clicked(GtkWidget *widget,gpointer data){
	guint16 Length,Width;
	Length=gtk_entry_get_text_length(GTK_ENTRY(g->entryl));
	Width=gtk_entry_get_text_length(GTK_ENTRY(g->entryw));
	if(Length==0 && Width==0){
		;/*do nothing*/
	}else{
		if(Length==0 && Width >0){
			gtk_entry_set_text(GTK_ENTRY(g->entryl),gtk_entry_get_text(GTK_ENTRY(g->entryw)));
		}else{
			gtk_entry_set_text(GTK_ENTRY(g->entryw),gtk_entry_get_text(GTK_ENTRY(g->entryl)));
		}
	}
}/*END FUNCTION : end function*/
/********************************************************************/
void on_spinbuttonGIR_value_changed(GtkSpinButton *widget,gpointer data){
	gint sum;
	const gchar *ret=0;
	gint PAV=gtk_spin_button_get_value(GTK_SPIN_BUTTON(g->spinbuttonPAV));
	gint SHP=gtk_spin_button_get_value(GTK_SPIN_BUTTON(g->spinbuttonSHP));
	gint GIR=gtk_spin_button_get_value(widget);/*get the current value*/
	sum =GIR+PAV+SHP;
	ret=g_strdup_printf("%d",sum);
	gtk_entry_set_text(GTK_ENTRY(g->entryBdialog),ret);
}/*END FUNCTION : adjustments spinbutton*/
/********************************************************************/
void on_spinbuttonPAV_value_changed(GtkSpinButton *widget,gpointer data){
	gint sum;
	const gchar *ret=0;
	gint GIR=gtk_spin_button_get_value(GTK_SPIN_BUTTON(g->spinbuttonGIR));
	gint SHP=gtk_spin_button_get_value(GTK_SPIN_BUTTON(g->spinbuttonSHP));
	gint PAV=gtk_spin_button_get_value(widget);/*get the current value*/
	sum =GIR+PAV+SHP;
	ret=g_strdup_printf("%d",sum);
	gtk_entry_set_text(GTK_ENTRY(g->entryBdialog),ret);
}/*END FUNCTION : adjustments spinbutton*/
/********************************************************************/
void on_spinbuttonSHP_value_changed(GtkSpinButton *widget,gpointer data){
	gint sum;
	const gchar *ret=0;
	gint GIR=gtk_spin_button_get_value(GTK_SPIN_BUTTON(g->spinbuttonGIR));
	gint PAV=gtk_spin_button_get_value(GTK_SPIN_BUTTON(g->spinbuttonPAV));
	gint SHP=gtk_spin_button_get_value(widget);/*get the current value*/
	sum =GIR+PAV+SHP;
	ret=g_strdup_printf("%d",sum);
	gtk_entry_set_text(GTK_ENTRY(g->entryBdialog),ret);
}/*END FUNCTION : adjustments spinbutton*/
/********************************************************************/
void on_buttonADJClearAll_clicked(GtkWidget *widget,gpointer data){
	gtk_entry_set_text(GTK_ENTRY(g->entryBdialog),"0");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(g->spinbuttonGIR),0);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(g->spinbuttonPAV),0);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(g->spinbuttonSHP),0);
	/*reset all adjustments in the dialog to zero*/
}/*END FUNCTION : */
/********************************************************************/
void on_buttonApplyBulgeDialog_clicked(GtkWidget *widget,gpointer data){
	const gchar *dialogentry;
	dialogentry=gtk_entry_get_text(GTK_ENTRY(g->entryBdialog));
	gtk_entry_set_text(GTK_ENTRY(g->entryb),dialogentry);
	Calculate(g->entryCUT,NULL);/*runs calculate function*/
}/*END FUNCTION : opens dialog for adjustments*/
/********************************************************************/
void on_savePREF_clicked(GtkWidget *widget,gpointer data){
	save_preferences();
}/*END FUNCTION : saves preferences*/
/********************************************************************/
void toggleEditableFactor(GtkWidget *widget,gpointer data){
	gchar *E;
	if(toggle_button_callback(g->manoverideFCB,NULL)==TRUE){
		toggleEntryEditable(g->entryf,TRUE);
		E="manual overide of factor:: ON";
	}else{
		toggleEntryEditable(g->entryf,FALSE);
		E="manual overide of factor :: OFF";
	}
	g->delsbid=gtk_statusbar_push (GTK_STATUSBAR (g->statusbar ), GPOINTER_TO_INT (g->context_id), E);
	//g_free(E); crashes from 0.9.9 onwards
	/*make factor editable for overiding program*/
}/*END FUNCTION : */
/********************************************************************/
void on_interpolateCB_toggled(GtkWidget *widget,gpointer data){
	Calculate(g->interpolateCB,NULL);
}/*END FUNCTION : update even if GO button not clicked*/
/********************************************************************/
void on_entryl_activate(GtkWidget *widget,gpointer data){
	/**/
}/*END FUNCTION : */
/**************************************************
 * 
 * END CALLBACK FUNCTIONS
 * 
 **************************************************/
void OLD_Calculate(GtkWidget *widget, gpointer data){}
void Calculate(GtkWidget *widget, gpointer data){
	//pref_file = g_fopen (path, "a");
	if(DEBUG==TRUE){
		++debugCounter;
		if(DEBUG)g_print("(%d) %s function called line: %d\n",debugCounter,__FUNCTION__,__LINE__);
	}
	gint gtk_entry_bulge_max=gtk_entry_get_max_length(GTK_ENTRY(g->entryb));
	gint gtk_entry_depthepth_max=gtk_entry_get_max_length(GTK_ENTRY(g->entryd));
	gchar *ltmp="";/*tmp holder for swapping length and width if they are reversed*/
	gchar dble2string[gtk_entry_depthepth_max];
	gchar lwRatioString[100];
	gchar dpText[100];
	gchar isAdjustmentPercentage[gtk_entry_bulge_max];
	gchar isDepthPercentage[gtk_entry_depthepth_max];
	gchar *pchkPerc=NULL;/*check if Bulge or Depth have percentage figure?*/
	gchar *bulgeString;/*prints to statusbar*/
	guint16 textlength;
	gboolean isInterpolateChecked;
	gboolean calc_check_log_enabled=toggle_button_callback(g->CBEnablLogging,NULL);/*is logging enabled?*/
	gdouble _printedanswer=0; /*answer*/
	gdouble _length=0; /*length*/
	gdouble _width=0; /*width*/
	gdouble _depth=0;/*depth*/
	gdouble _depthp=0;/*depth percentage*/
	gdouble _specific_gravity=0;/*specific gravity*/
	gdouble _factor=0;/*factor*/
	gdouble _adjustment=0;/*bulge*/
	gdouble _adjustment2=0;/*bulge temp*/
	gdouble _tmp=0;/*temp (swaps l and w)*/
	gdouble _result=0;/*answer*/
	gdouble _LWratio=0;/*length to width ratio*/
	gdouble _AV;/*length to width ratio*/
	gdouble logTextAnswer;/*writes answer _recut to log file*/
	/*gdouble factor=0;default round brilliant cut diamond factor*/
	const gchar *bigDepthWarning="WARNING: depth exceeded length or width";
	const gchar *checkInputCompletion;//check and update the SG if the user types in the full name of the stone;
	const gchar *pdble2string;/*will point to dble2string[] for g_specific_gravitytrdup_print*/
	const gchar *sba;/*raw text answer from label*/
	const gchar *rRecutWeight=0;/*calculates the recut weight*/
	const gchar *aText = gtk_label_get_text(GTK_LABEL(g->answer));/*answer*/
	const gchar *lText = gtk_entry_get_text(GTK_ENTRY(g->entryl));/*length*/
	const gchar *wText = gtk_entry_get_text(GTK_ENTRY(g->entryw));/*width*/
	const gchar *dText = gtk_entry_get_text(GTK_ENTRY(g->entryd));/*depth*/
	const gchar *sText = gtk_entry_get_text(GTK_ENTRY(g->entrys));/*specific gravity*/
	const gchar *fText = gtk_entry_get_text(GTK_ENTRY(g->entryf));/*factor*/
	const gchar *bText = gtk_entry_get_text(GTK_ENTRY(g->entryb));/*bulge*/
	const gchar *gemText = (isDiamond==TRUE)?DEFDGLABEL:gtk_entry_get_text(GTK_ENTRY(g->entryGEM));/*gemstone*/
	const gchar *cutText = gtk_entry_get_text(GTK_ENTRY(g->entryCUT));/*cut*/
	const gchar *logText;/*writes to log file*/
	/*CONVERT TEXT INPUT TO DOUBLE*/
	sscanf(aText, "%lf", &_printedanswer);/*convert answer to double*/
	sscanf(lText, "%lf", &_length);/*convert length to double*/
	sscanf(wText, "%lf", &_width);/*convert width to double*/
	sscanf(dText, "%lf", &_depth);/*convert depth to double*/
	sscanf(sText, "%lf", &_specific_gravity);/*convert sg to double*/
	sscanf(fText, "%lf", &_factor);/*convert factor to double*/
	sscanf(bText, "%lf", &_adjustment);/*convert adjustment to double*/
	/*CONVERT TEXT INPUT TO STRING NON CONST*/
	sscanf(dText, "%s", isDepthPercentage);/*is depth a percentage ie % was entered?*/
	sscanf(bText, "%s", isAdjustmentPercentage);/*is bulge a percentage ie % was entered?*/
	/********************************************************/
	textlength=gtk_entry_get_text_length(GTK_ENTRY(g->entryl));
	if(textlength==0)_length=_width;/*if left blank use width field's value*/
	textlength=gtk_entry_get_text_length(GTK_ENTRY(g->entryw));
	if(textlength==0)_width=_length;/*if left blank use length field's value*/
	textlength=gtk_entry_get_text_length(GTK_ENTRY(g->entryd));
	if(textlength==0)_depth=returnDepthIfEmpty(_width,0.6);/*if left blank depth = 60%*/
	if(strcmp(cutText,DIAROSE)==0 && textlength==0){/*changes rose depth to 34% considered the average*/
		_depth= returnDepthIfEmpty(_width,0.34);
		/*_depth= returnDepthIfEmpty(((_length+_width)/2),0.34);*/
	}
	if(strcmp(cutText,DIATAPBAG)==0){
		_width=retTaperedDiamondWidth(wText);
	}
	if(isDiamond==FALSE){
		checkInputCompletion= checkInputSGequalslistedSG(gemText);
		if(checkInputCompletion!=NULL){/*null pointer not returned*/
			gtk_entry_set_text(GTK_ENTRY(g->entrys), checkInputCompletion);/*update the interface*/
		}/*check if gem input string and sg match*/
	}else{/*it is a diamond*/
		_specific_gravity=1;/*set SG to 1*/
	}
	/*if left blank use length field's value*/
	textlength=gtk_entry_get_text_length(GTK_ENTRY(g->entryb));
	if(textlength==0 || *bText=='0')_adjustment=ZERO;
	if(isDiamond==FALSE && gtk_entry_get_text_length(GTK_ENTRY(g->entryCUT))==0)_factor=0;
	/*if it's a GEM selection, but there's no cut make the factor 0*/
	/*********************BULGE********************************/
	/*if left blank use width field's value*/
	pchkPerc=strrchr(isAdjustmentPercentage,'%');
	if(pchkPerc==NULL){
		_adjustment2=_adjustment;/*_adjustment2 = 20*/
		_adjustment=1+(_adjustment*0.01);
		if(_adjustment<0){/*it could be negative for very thin girdles*/
			_adjustment2=_adjustment;/*_adjustment2 = 20*/
			_adjustment=1-(_adjustment*0.01);
		}
		bulgeString = g_strdup_printf ("%4.0f%%", _adjustment2);/*convert 1.20 to string*/
	}else{
		_adjustment2=_adjustment;/*_adjustment2 = 20*/
		_adjustment=1+(_adjustment*0.01);
		bulgeString = g_strdup_printf ("%4.0f%%", _adjustment2);/*convert 20% to string*/
	}
	/*********************DEPTH PERCENTAGE********************************/
	pchkPerc=strrchr(isDepthPercentage,'%');/*true/false*/
	if(_width>0){
		if(pchkPerc==NULL){
			_depthp=depthPercentage(_depth,_width);
		}else{
			/*there should be a % figure in string, but what if the user just types in a %?*/
			_depth=_width*(_depth*0.01);
			_depthp=depthPercentage(_depth,_width);
		}
	}/*END if(strlen(w)>0)*/
	else{
		_depthp=0;
	}
	print_DP_IMAGE_PIX(_depthp);
	/********************************************************************/
	sprintf(dpText, "Depth%%: %4.2lf",_depthp);
	gtk_label_set_text(GTK_LABEL(g->labelDP), dpText);
	/********************************************************************/
	/*now find the l/r ratio :: used for emerald cuts etc*/
	if((_width > _length) && strcmp(cutText,DIATAPBAG)!=0){/*swap around if input is around the wrong way and it's not a tapered baguette*/
		_tmp=_width;
		_width=_length;
		_length=_tmp;
		ltmp=g_strdup(lText);
		gtk_entry_set_text(GTK_ENTRY(g->entryl), wText);
		gtk_entry_set_text(GTK_ENTRY(g->entryw), ltmp);
	}
	_LWratio=lwratio(_length,_width);
	sprintf(lwRatioString, "L:W Ratio: %4.1lf:1",_LWratio);
	gtk_label_set_text(GTK_LABEL(g->labelLW), lwRatioString);
	/************************SWAP AROUND IF ERROR************************/
	isInterpolateChecked=toggle_button_callback(g->interpolateCB,NULL);
	/*check if the interpolate CB button is checked or not*/
	if(checkManOverideStatus()==FALSE)/*only update if man overide not checked*/
		_factor=returnCorrectedFactor(_factor,cutText,_LWratio,isInterpolateChecked,data);
	/*if manoveride is checked none of this function needs to be called*/
	_result = resultGenerator(_length,_width,_depth,_specific_gravity,_adjustment,_factor,_LWratio);/*main calculation function*/
	if(showRecut==TRUE)
		rRecutWeight=returnRecutWeight(_length,_width,_depth,cutText,use1000thcarat,_result);
	/*even though _result is altered in the next line we do not estimate recuts on Pearls anyway*/
	if(strcmp(gemText,PEARL)==0){
		_result=_result/MOMME;
		pdble2string = g_strdup_printf("<big>%.2lf momme</big>",_result);
	}else{
		if(_length<=thousandsThreshold || use1000thcarat==TRUE){
			pdble2string = g_strdup_printf("<big>%.3lf ct</big>",_result);
		}else{
			pdble2string = g_strdup_printf("<big>%.2lf ct</big>",_result);
		}/*end IFELSE 1000th ct*/
	}//END NOT PEARL
	strcpy(dble2string,pdble2string);
	/*
	 * 
	 * style = gtk_widget_get_style(g->answer);
	 * pango_font_description_set_weight(style->font_desc, PANGO_WEIGHT_BOLD);
	 * gtk_widget_modify_font(g->answer, style->font_desc);
	 * 
	 */
	gtk_label_set_markup(GTK_LABEL(g->answer), dble2string);/*print result to interface*/
	sba = gtk_label_get_text(GTK_LABEL(g->answer));
	if(showRecut==TRUE){
		//gtk_widget_show(g->hboxRecutContainer);
		gtk_widget_show(g->vboxRecut);
		gtk_label_set_markup(GTK_LABEL(g->answerRecut),rRecutWeight);
	}else{
		//gtk_widget_hide(g->hboxRecutContainer);
		gtk_widget_hide(g->vboxRecut);
		gtk_label_set_markup(GTK_LABEL(g->answerRecut),"");
	}//end showRecut==TRUE
	_AV=returnAverage(_length,_width);/*return _length + _Width /2*/
	if(isDiamond==TRUE)/*it's a diamond no need to print SG*/
	{
		if(usesAvDiamSQ==TRUE){
			g->sba2 = g_strdup_printf ("<small>%s [%s] %4.2f<sup>2</sup>x%4.2f+%s=%s (%4.3f)</small>",cutText,gemText,_AV,_depth,bulgeString,sba,_factor);
			logText=g_strdup_printf ("%s [%s] %4.2f(sq)x%4.2f+%s=%s (%4.3f)",cutText,gemText,_AV,_depth,bulgeString,sba,_factor);
			logTextAnswer=_result;
		}else{
			g->sba2 = g_strdup_printf ("<small>%s [%s] %4.2fx%4.2fx%4.2f+%s=%s (%4.3f)</small>",cutText,gemText,_length,_width,_depth,bulgeString,sba,_factor);
			logText=g_strdup_printf ("%s [%s] %4.2fx%4.2fx%4.2f+%s=%s (%4.3f)",cutText,gemText,_length,_width,_depth,bulgeString,sba,_factor);
			logTextAnswer=_result;
		}
		/*if below ?mm diameter print extra decimal point*/
	}else{//not diamond so print SG
		if(usesAvDiamSQ==TRUE){
			g->sba2 = g_strdup_printf ("<small>%s [%s] %4.2f<sup>2</sup>x%4.2fx%4.2f+%s=%s (%4.3f)</small>",cutText,gemText,_AV,_depth,_specific_gravity,bulgeString,sba,_factor);
			logText=g_strdup_printf ("%s [%s] %4.2f(sq)x%4.2fx%4.2f+%s=%s (%4.3f)",cutText,gemText,_AV,_depth,_specific_gravity,bulgeString,sba,_factor);
			logTextAnswer=_result;
		}else{
			g->sba2 = g_strdup_printf ("<small>%s [%s] %4.2fx%4.2fx%4.2fx%4.2f+%s=%s (%4.3f)</small>",cutText,gemText,_length,_width,_depth,_specific_gravity,bulgeString,sba,_factor);
			logText=g_strdup_printf ("%s [%s] %4.2fx%4.2fx%4.2fx%4.2f+%s=%s (%4.3f)",cutText,gemText,_length,_width,_depth,_specific_gravity,bulgeString,sba,_factor);
			logTextAnswer=_result;
		}
	}//if(isDiamond==TRUE)
	gtk_label_set_markup(GTK_LABEL(g->labelFA),g->sba2);/*print result to interface*/
	if(calc_check_log_enabled==TRUE){
		//~ logText="john";
		//~ logTextAnswer=4.55;
		write2LogFile(logText,logTextAnswer);
	}
	/************************PRINT SWAP AROUND IF ERROR*******************/
	if(_depth > _width || _depth > _length)
		/*depth should not be usually greater than width*/
		g->delsbid=gtk_statusbar_push (GTK_STATUSBAR (g->statusbar ), GPOINTER_TO_INT (data), bigDepthWarning);
	firstRun=FALSE;/*stops this function being called on first run when TRUE*/
	//g_free (path);
}/*END CALCULATE FUNCTION*/
/********************************************************************
 * 
 * 
 * 
 * 
 * END CALCULATE FUNCTION
 * 
 * 
 * 
 * 
 * 
 *******************************************************************/
void place_Cut_Legend_in_help_file(){
	GdkPixmap *pixmap;
	GdkBitmap *mask;
	GtkStyle *style;
	GtkWidget *pixmapwid;
	/* GtkWidget is the storage type for widgets */
	/* now for the pixmap from gdk */
	style = gtk_widget_get_style( g->window );
	pixmap = gdk_pixmap_create_from_xpm_d( g->window->window, &mask,
			&style->bg[GTK_STATE_NORMAL],
			(gchar **)cutplate );
	/* a pixmap widget to contain the pixmap */
	pixmapwid = gtk_image_new_from_pixmap( pixmap, mask );
	gtk_widget_show( pixmapwid );
	if(countHelpPixmap==1)gtk_box_pack_start (GTK_BOX (g->hboxCUT_PLATE), pixmapwid, FALSE, FALSE, 0);
	countHelpPixmap++;/*extern variable in pixmaps.h*/
	g_object_unref(pixmap);
	g_object_unref(mask);
}/*END FUNCTION : */
/********************************************************************/ 
GdkPixbuf *returnNewGemXPM(const gchar *m){
	/*returns a pixbuf of the array gemstoneXPM with background color from 3rd element of gemStone array*/
	const gchar *tXPM[GEMCUTXPMARRAYLENGTH];
	GdkPixbuf* l_gem_pixbuf;
	guint16 i;
	for(i=0;i<GEMCUTXPMARRAYLENGTH;++i){
		if(i==GEMCUTXPMRGBOVERLAY){
			tXPM[i]=m;
		}else{
			tXPM[i]=gemstoneXPM[i];
		}
	}
	l_gem_pixbuf=gdk_pixbuf_new_from_xpm_data(tXPM);
	return l_gem_pixbuf;
}/*END FUNCTION : */
/********************************************************************/ 
GdkPixbuf *returnNewDPXPM(gint16 dp){
	/*returns a pixbuf of the array gemstoneXPM with background color from 3rd element of gemStone array*/
	guint16 colors=9;/*number of colors + 1*/
	guint16 k;
	guint16 i;
	gint16 orgDP;/*pointer to original depth percentage*/
	orgDP=dp;
	dp=(dp/2)+colors;
	GdkPixbuf* dp_gem_pixbuf;
	gchar *fill=" OXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO ";
	gchar *line="@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	for(k=0;LW_Legend[k]!=NULL;++k){}/*count image array*/
	const gchar *tmpXPM[k];
	for(i=0;i<k;++i){
		if(i>colors && i<dp){
			tmpXPM[i]=fill;
		}else{
			tmpXPM[i]=LW_Legend[i];
		}
		if(i==dp || i==(k-1))/*i==(k-1) prints the black line at the bottom for 98-100% depth entrys - */
			tmpXPM[i]=line;/*print percentage line*/
	}//end for
	if(orgDP >DEPTHPERCENTAGELOWERLIMIT && orgDP<DEPTHPERCENTAGEUPPERLIMIT){/*only print this image if the percentage are reasonable*/
		dp_gem_pixbuf=gdk_pixbuf_new_from_xpm_data(tmpXPM);
	}else{
		dp_gem_pixbuf=gdk_pixbuf_new_from_xpm_data((const gchar**)check_depth);
	}
	if(DEBUG==TRUE)g_print("array of LW_Legend is %d in length\n",k); 
	return dp_gem_pixbuf;
}/*END FUNCTION : */
/********************************************************************/ 
void print_GEM_IMAGE(const gchar* gemColorMask){
	/*
	 * GtkWidget *gem_image;
	 * GdkPixbuf* gem_pixbuf;
	 * found in pixmaps_s.h
	 */
	showImageFields(TRUE);
	gem_pixbuf=returnNewGemXPM(gemColorMask);
	if(countPixmapGem==1){
		gem_image = gtk_image_new_from_pixbuf(gem_pixbuf);
		gtk_widget_show( GTK_WIDGET(gem_image) );
		gtk_container_add(GTK_CONTAINER(g->hboxGEM_IMAGE), GTK_WIDGET(gem_image));
	}else{
		gtk_image_set_from_pixbuf(GTK_IMAGE(gem_image),gem_pixbuf);
		gtk_widget_show( GTK_WIDGET(gem_image));
		if(gtk_entry_get_text(GTK_ENTRY(g->entryGEM))!=0)
			tooltip(gem_image,gtk_entry_get_text(GTK_ENTRY(g->entryGEM)));
	}
	++countPixmapGem;
}/*END FUNCTION : */
/********************************************************************/ 
void print_GEM_IMAGE_PIX(char** cut2print){
	/*
	 * GtkWidget *gem_image;
	 * GdkPixbuf* gem_pixbuf;
	 * found in pixmaps_s.h
	 */
	showImageFields(TRUE);
	gem_pixbuf=gdk_pixbuf_new_from_xpm_data((const char**)cut2print);
	if(countPixmapGem==1){
		gem_image = gtk_image_new_from_pixbuf(gem_pixbuf);
		gtk_widget_show( GTK_WIDGET(gem_image) );
		gtk_container_add(GTK_CONTAINER(g->hboxGEM_IMAGE), GTK_WIDGET(gem_image));
	}else{
		gtk_image_set_from_pixbuf(GTK_IMAGE(gem_image),gem_pixbuf);
		gtk_widget_show( GTK_WIDGET(gem_image));
	}
	(isDiamond==TRUE)?tooltip(GTK_WIDGET(gem_image),DIAMOND):tooltip(GTK_WIDGET(gem_image),"gemstone");
	++countPixmapGem;
}/*END FUNCTION : */
/********************************************************************/ 
void print_RECUTIMAGE_PIX(char** cut2print,const gchar *toolTip,const gchar* labelling){
	/*
	 * GtkWidget *recut_image;
	 * GdkPixbuf* recut_pixbuf;
	 * found in pixmaps_c.h
	 */
	const gchar *labelling_markup;
	labelling_markup=g_strdup_printf("<span foreground=\"#666666\"><small><i>%s</i></small></span>",labelling);
	showImageFields(TRUE);
	recut_pixbuf=gdk_pixbuf_new_from_xpm_data((const char**)cut2print);
	if(countPixmapRecutIm==1){
		recut_image = gtk_image_new_from_pixbuf(recut_pixbuf);
		gtk_widget_show( GTK_WIDGET(recut_image) );
		gtk_container_add(GTK_CONTAINER(g->hboxRecutLegend), GTK_WIDGET(recut_image));
	}else{
		gtk_image_set_from_pixbuf(GTK_IMAGE(recut_image),recut_pixbuf);
		gtk_widget_show( GTK_WIDGET(recut_image));
	}
	gtk_label_set_markup(GTK_LABEL(g->labelRecutLabelling),labelling_markup);
	tooltip(GTK_WIDGET(recut_image),toolTip);
	++countPixmapRecutIm;
}/*END FUNCTION : */
/********************************************************************/ 
void print_DP_IMAGE_PIX(gdouble dp){
	/*
	 * GtkWidget *dp_image;
	 * GdkPixbuf* dp_pixbuf;
	 * found in pixmaps_c.h
	 */
	gint16 dpi=(gint16)dp;
	gchar *dpString;
	showImageFields(TRUE);
	dp_pixbuf=returnNewDPXPM(dpi);
	if(countPixmapDP==1){
		dp_image = gtk_image_new_from_pixbuf(dp_pixbuf);
		gtk_widget_show( GTK_WIDGET(dp_image) );
		gtk_container_add(GTK_CONTAINER(g->hboxDP_IMAGE), GTK_WIDGET(dp_image));
	}else{
		gtk_image_set_from_pixbuf(GTK_IMAGE(dp_image),dp_pixbuf);
		gtk_widget_show( GTK_WIDGET(dp_image));
	}
	dpString = g_strdup_printf ("%4.2f%%", dp);/*convert dp to string*/
	tooltip(GTK_WIDGET(dp_image),dpString);
	++countPixmapDP;
}/*END FUNCTION : */
/********************************************************************/ 
void print_ADJUST_XPM(){
	/*
	 * GtkWidget *adjxpm_image;
	 * GdkPixbuf* adjxpm_pixbuf;
	 * found in pixmaps_s.h
	 */
	char** image2print=adjustIcon_xpm;
	gchar *adjxpmTooltip;
	adjxpm_pixbuf=gdk_pixbuf_new_from_xpm_data((const char**)image2print);
	adjxpm_image = gtk_image_new_from_pixbuf(adjxpm_pixbuf);
	gtk_widget_show( GTK_WIDGET(adjxpm_image) );
	gtk_button_set_image(GTK_BUTTON(g->buttonADJ),GTK_WIDGET(adjxpm_image));
	adjxpmTooltip = g_strdup_printf ("adjustments for girdle thickness, bulge etc Alt+a");
	tooltip(GTK_WIDGET(adjxpm_image),adjxpmTooltip);
}/*END FUNCTION : */
/********************************************************************/ 
void on_entryGEM_activate(GtkWidget *widget, gpointer data){
	updateGemImageIfUserEnteredWholeString(gtk_entry_get_text(GTK_ENTRY(g->entryGEM)));
	Calculate(NULL,NULL);
}/*END FUNCTION : */
/********************************************************************/ 
void need_LW_or_Diameter_Labelling(){
	gboolean isRoundish=1;/*initialise*/
	gint lengthOfInputText=gtk_entry_get_text_length(GTK_ENTRY(g->entryCUT));
	gchar trimmedText[lengthOfInputText+1];
	const gchar *cu =gtk_entry_get_text(GTK_ENTRY(g->entryCUT));
	Cuts *ListOfCuts;
	Cuts *a;
	/*returns the name of the cut to print*/
	strcpy(trimmedText,cu);
	g_strstrip(trimmedText);
	if(isDiamond==TRUE){
		a=DiaCut_list;
	}else{
		a=GemCut_list;
	}
	for(ListOfCuts=a;ListOfCuts && ListOfCuts->cut; ListOfCuts++) {
		if(strcmp(ListOfCuts->cut,trimmedText)==0){
			isRoundish=ListOfCuts->roundish;
			break;
			/*break; we found a match. Let's get out of here*/
		}
	}//end for
	if(isRoundish==TRUE){
		gtk_label_set_text(GTK_LABEL(g->labell),"Diameter");
		gtk_label_set_text(GTK_LABEL(g->labelw),"Diameter");
		gtk_label_set_text(GTK_LABEL(g->labelLeqW),"D1=D2");
	}else{/*print Diameter*/
		gtk_label_set_text(GTK_LABEL(g->labell),"Length");
		gtk_label_set_text(GTK_LABEL(g->labelw),"Width");
		gtk_label_set_text(GTK_LABEL(g->labelLeqW),"L=W");
		if(strcmp(cu,DIATAPBAG)==0){
			gtk_label_set_text(GTK_LABEL(g->labelw),"Max + Min Width (ie 5,3)");
		}
	}/*print LW*/
}/*END FUNCTION : */
/********************************************************************/ 
gboolean usesAvDiametersquared(const gchar *Cut){
	gint lengthOfInputText=strlen(Cut);
	gchar trimmedText[lengthOfInputText+1];
	Cuts *ListOfCuts;
	Cuts *a;
	/*returns the name of the cut to print*/
	strcpy(trimmedText,Cut);
	g_strstrip(trimmedText);
	if(isDiamond==TRUE){
		a=DiaCut_list;
	}else{
		a=GemCut_list;
	}
	for(ListOfCuts=a;ListOfCuts && ListOfCuts->cut; ListOfCuts++) {
		if(strcmp(ListOfCuts->cut,trimmedText)==0){
			usesAvDiamSQ=ListOfCuts->useAvDiameter;/*gboolean GLOBAL in functions.h*/
			break;
			/*break; we found a match. Let's get out of here*/
		}
	}
	return usesAvDiamSQ;
}/*END FUNCTION : */
/********************************************************************/ 
void print_CUT_IMAGE(gpointer* cut2print){
	showImageFields(TRUE);
	const gchar **xpm=(const gchar**)cut2print;
	cut_pixbuf=gdk_pixbuf_new_from_xpm_data(xpm);
	if(countPixmapCut==1){
		cut_image = gtk_image_new_from_pixbuf(cut_pixbuf);
		gtk_widget_show( GTK_WIDGET(cut_image) );
		gtk_container_add(GTK_CONTAINER(g->hboxCUT_IMAGE), GTK_WIDGET(cut_image));
	}else{
		gtk_image_set_from_pixbuf(GTK_IMAGE(cut_image),cut_pixbuf);
		gtk_widget_show( GTK_WIDGET(cut_image));
	}
	tooltip(cut_image,gtk_entry_get_text(GTK_ENTRY(g->entryCUT)));
	++countPixmapCut;
	need_LW_or_Diameter_Labelling();
}/*END FUNCTION : */
/********************************************************************/ 
void tooltip(GtkWidget *widget,const gchar *message){
	gint lengthOfInputText=strlen(message)+1;
	gchar trimmedText[lengthOfInputText];
	strcpy(trimmedText,message);
	g_strstrip(trimmedText);
	GtkTooltips *tooltipsA;
	tooltipsA = gtk_tooltips_new();
	gtk_tooltips_set_tip(tooltipsA, widget, trimmedText, NULL);
}/*END FUNCTION : */
/********************************************************************/
void showImageFields(gboolean show){
	if(show==TRUE){
		/*show the image and cut fields*/
		gtk_widget_show(g->vboxIMAGEcont);
	}else{
		/*hide the image and cut fields*/
		gtk_widget_hide(g->vboxIMAGEcont);
	}
}/*END FUNCTION : showImageFields(gboolean show)*/
/********************************************************************/
gdouble interpolateFancyFactor(gdouble LR,gdouble HR,gdouble LF,gdouble HF,gdouble input){
	gdouble r,A,B,C,Z;
	A=((input-LR)/LR)*100;
	B=((HR-LR)/LR)*100;
	C=A/B;
	Z=(LF+((HF-LF))*C);
	r=Z;
	return r;
}/*END FUNCTION : */
/********************************************************************/
gdouble returnCorrectedFactor(gdouble factor,const gchar *cutT,gdouble lw_ratio,gboolean interpolate,int *data){
	if(isDiamond==TRUE){
		if(lw_ratio > 3){
			g->delsbid=gtk_statusbar_push (GTK_STATUSBAR (g->statusbar ), GPOINTER_TO_INT (data), "*LW Ratio exceeds 3:1 Please adjust factor manually");
			gchar *redLabel="<span foreground=\"red\">Factor*</span>";
			gtk_label_set_markup(GTK_LABEL (g->labelFactor), redLabel);
			tooltip(g->labelFactor,"Length to Width ratio exceeds 3:1. Please check");
		}else{
			gchar *returntonormal="Factor";
			gtk_label_set_text(GTK_LABEL (g->labelFactor), returntonormal);
			tooltip(g->labelFactor,"Factor");
		}/*this will reset redLable to default if it has already been triggered*/
		if(strcmp(cutT,FANCYDIAMARQUISE)==0){ //MARQUISE
			if(DEBUG==TRUE)g_print("%s %d :: %s (%d):%f\n",__FUNCTION__,__LINE__,cutT,interpolate,lw_ratio);
			factor = returnFancyFactor(Fancy_MARQ_FACTOR_list,lw_ratio,interpolate);
		}//if(strcmp(selectedCut,FANCYDIAMARQUISE)
		/*************************/
		if(strcmp(cutT,FANCYDIAEMERALD)==0){ // EMERALD
			if(DEBUG==TRUE)g_print("%s %d :: %s (%d):%f\n",__FUNCTION__,__LINE__,cutT,interpolate,lw_ratio);
			factor = returnFancyFactor(Fancy_EMER_FACTOR_list,lw_ratio,interpolate);
		}//strcmp(selectedCut,FANCYDIAEMERALD)
		/*************************/
		if(strcmp(cutT,FANCYDIAPEAR)==0){ // PEAR
			if(DEBUG==TRUE)g_print("%s %d :: %s (%d):%f\n",__FUNCTION__,__LINE__,cutT,interpolate,lw_ratio);
			factor = returnFancyFactor(Fancy_PEAR_FACTOR_list,lw_ratio,interpolate);
		}//if(strcmp(selectedCut,FANCYDIAPEAR)
		/*************************/
		return factor;
	}else{//end isDiamond
		return factor;
	}/*end ELSEIF*/
}/*END FUNCTION : */
/********************************************************************/
gdouble returnFancyFactor(FancyDFactor *a,gdouble lw_ratio,gboolean Interpolate){
	gdouble return_new_factor=0,lowratio=0,highratio=0,lowfactor=0,highfactor=0;
	const gchar *fString;
	guint16 i=0;/*run through array looking for threshold*/
	guint16 j=0;/*Lower thresholds' freeze*/
	guint16 k=0;/*Higher thresholds' freeze*/
	while(a[i].lwBarrier!=0){
		if(DEBUG==TRUE)g_print("[%d] %f %f :: %f\n",i,a[i].lwBarrier,a[i].fancyDFactor,lw_ratio);
		if(lw_ratio >= a[i].lwBarrier){
			return_new_factor=a[i].fancyDFactor;
			j=i;
		}
		++i;
	}/*end WHILE*/
	k=j+1;
	if(Interpolate==TRUE && j!=(i-1)){
		/*if j = i which is the last value before 0 we shouldn't interpolate as te stone is beyond 3:1 ratio*/
		lowratio=a[j].lwBarrier;
		lowfactor=a[j].fancyDFactor;
		highratio=a[k].lwBarrier;
		highfactor=a[k].fancyDFactor;
		return_new_factor=interpolateFancyFactor(lowratio,highratio,lowfactor,highfactor,lw_ratio);
	}
	if(DEBUG==TRUE)g_print("returning factor (%f) from function :: %s\n",return_new_factor,__FUNCTION__);
	if(DEBUG==TRUE)g_print("j=%d\nlowratio=%f\nhighratio=%f\nlowfactor=%f\nhighfactor=%f\n",j,lowratio,highratio,lowfactor,highfactor);
	fString=g_strdup_printf("%4.6f",return_new_factor);
	gtk_entry_set_text(GTK_ENTRY(g->entryf),fString);
	return return_new_factor;
}/*END FUNCTION : */
/********************************************************************/
const gchar *checkInputSGequalslistedSG(const gchar *inputText){/*check if gem input string and sg match*/
	gint lengthOfInputText=strlen(inputText)+1;
	gchar trimmedText[lengthOfInputText];
	strcpy(trimmedText,inputText);
	g_strstrip(trimmedText);
	const gchar *returnSG=NULL;
	GemStone *checkGemstoneList;
	for(checkGemstoneList=GemStone_list;checkGemstoneList && checkGemstoneList->name; checkGemstoneList++) {
		if(strcmp(checkGemstoneList->name,trimmedText)==0){
			returnSG=checkGemstoneList->specgrav;
			updateGemImageIfUserEnteredWholeString(gtk_entry_get_text(GTK_ENTRY(g->entryGEM)));
			/*break; we found a match. Let's get out of here*/
			/*while we're at it we will change the cut to round bead if PEARL is selected*/
		}
	}/*if we found the input gem string equals a gem in the database we change the sg to match that figure*/
	return returnSG;
}/*END checkInputSGequalslistedSG */
/********************************************************************/
void updateGemImageIfUserEnteredWholeString(const gchar *inputText){
	gint lengthOfInputText=strlen(inputText)+1;
	gchar trimmedText[lengthOfInputText];
	strcpy(trimmedText,inputText);
	g_strstrip(trimmedText);
	GemStone *findThisCutsColor;
	for(findThisCutsColor=GemStone_list;findThisCutsColor && findThisCutsColor->name; findThisCutsColor++) {
		if(strcmp(findThisCutsColor->name,trimmedText)==0){
			print_GEM_IMAGE(findThisCutsColor->colorMask);
			break;
			/*update the icon to show the correct color if user typed in complete name*/
		}
	}/*end for*/
}/*END updateGemImageIfUserEnteredWholeString*/
/********************************************************************/
gdouble resultGenerator(gdouble length,gdouble width,gdouble depth,gdouble sg,gdouble bulge,gdouble factor,gdouble lw_ratio){
	gdouble result,adjustedLWbyCut;
	const gchar *selectedCut=gtk_entry_get_text(GTK_ENTRY(g->entryCUT));
	adjustedLWbyCut=returnLengthWidthFormula(length,width,selectedCut);
	/*if it's a round bead we don't include depth*/
	result=adjustedLWbyCut*depth*sg*bulge*factor;
	if((strcmp(selectedCut,ROUNDBEAD)==0)){
		result=adjustedLWbyCut*sg*factor;
		gtk_entry_set_text(GTK_ENTRY(g->entryd), "");/*blank out the depth field*/
	}
	if(AreSame(bulge,ZERO))
		result=adjustedLWbyCut*depth*sg*factor;
	return result;
}/*END FUNCTION : */
/********************************************************************/
gboolean writetoSG(){
	return FALSE;
}/*END FUNCTION : */
/********************************************************************/
gdouble lwratio(gdouble length, gdouble width)
{
	gdouble r=0;
	if(length >0 && width >0)
		r=(length/width);
	return r;
}/*END FUNCTION : */
/********************************************************************/
gdouble depthPercentage(gdouble depth, gdouble width)
{
	gdouble r=(depth/width)*100;
	return r;
}/*END FUNCTION : */
/********************************************************************/
/* This function that lists all gem stones :: called from main.c */
void listGemCompletion(){
	GtkTreeIter iter;
	/*set up completion object*/
	g->completion = gtk_entry_completion_new();
	/*set completion on first column ie GEM_Stone*/
	gtk_entry_completion_set_text_column( g->completion, 0 );
	gtk_entry_set_completion( GTK_ENTRY( g->entryGEM ), g->completion );
	/* Create the ListStore, add "GemStones" and set it as the model of the entrycompletion */
	g_signal_connect(G_OBJECT (g->completion), "match-selected", G_CALLBACK (on_match_select_gemstone), NULL);
	g->model= gtk_list_store_new(3, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	for(listAllGems=GemStone_list; listAllGems && listAllGems->name; listAllGems++) {
		gtk_list_store_append(g->model, &iter);
		gtk_list_store_set(g->model, &iter,
				GemStone_NAME, listAllGems->name,
				GemStone_SG, listAllGems->specgrav,
				GemStone_Colour, listAllGems->colorMask,
				-1);
	}
	gtk_entry_completion_set_model( g->completion, GTK_TREE_MODEL( g->model ) );
}/*END FUNCTION : */
/********************************************************************/
void listCutCompletion(){
	GtkTreeIter iter;
	/*check the GEM STONE AND ADJust the cut accordingly*/
	g->completion = gtk_entry_completion_new();
	gtk_entry_completion_set_text_column( g->completion, 0 );
	gtk_entry_set_completion( GTK_ENTRY( g->entryCUT ), g->completion );
	g_signal_connect(G_OBJECT (g->completion), "match-selected", G_CALLBACK (on_match_select_cut), NULL);
	g->model= gtk_list_store_new(4, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_POINTER,G_TYPE_BOOLEAN);
	if(isDiamond==TRUE){/*is diamond radio button is selected?*/
		/*display diamond cuts*/
		gtk_entry_set_text(GTK_ENTRY(g->entrys), "");
		for(DiamondCuts=DiaCut_list; DiamondCuts && DiamondCuts->cut; DiamondCuts++) {
			gtk_list_store_append(g->model, &iter);
			gtk_list_store_set(g->model, &iter,
					Cut_NAME, DiamondCuts->cut,
					Cut_FACTOR, DiamondCuts->factor,
					Cut_IMAGE, DiamondCuts->image,
					Cut_Roundness, DiamondCuts->roundish,
					-1);
		}
	}else{/*if gem radio button is selected?*/
		/*make SG editable*/
		/*display gemcuts*/
		for(GemCuts=GemCut_list; GemCuts && GemCuts->cut; GemCuts++) {
			gtk_list_store_append(g->model, &iter);
			gtk_list_store_set(g->model, &iter,
					Cut_NAME, GemCuts->cut,
					Cut_FACTOR, GemCuts->factor,
					Cut_IMAGE, GemCuts->image,
					Cut_Roundness, DiamondCuts->roundish,
					-1);
		}
	}
	/*make sure the image is updated after the user has typed in the whole gem name*/
	gtk_entry_completion_set_model( g->completion, GTK_TREE_MODEL( g->model ) );
}/*END FUNCTION : */
/********************************************************************/
gboolean on_match_select_gemstone(GtkEntryCompletion *widget,GtkTreeModel *model,GtkTreeIter *iter,gpointer user_data)
{
	toggleEntryEditable(g->entrys,TRUE);/*make SG editable*/
	GValue value = {0, };
	GValue value_gem_image = {0, };
	gtk_tree_model_get_value(model, iter, GemStone_SG, &value);
	gtk_tree_model_get_value(model, iter, GemStone_Colour, &value_gem_image);
	gtk_entry_set_text(GTK_ENTRY(g->entrys),g_value_get_string(&value) );
	g_value_unset(&value);
	g_value_unset(&value_gem_image);
	return FALSE;
}/*END FUNCTION : */
/********************************************************************/
gboolean on_match_select_cut(GtkEntryCompletion *widget,GtkTreeModel *model,GtkTreeIter *iter,gpointer user_data)
{
	GValue value = {0, };
	GValue ptr_2_cut_image = {0, };
	gtk_tree_model_get_value(model, iter, Cut_FACTOR, &value);
	gtk_tree_model_get_value(model, iter, Cut_IMAGE, &ptr_2_cut_image);
	gtk_entry_set_text(GTK_ENTRY(g->entryf),g_value_get_string(&value) );
	g_value_unset(&value);
	g_value_unset(&ptr_2_cut_image);
	return FALSE;
}/*END FUNCTION : */
/********************************************************************/
void toggleEntryEditable(GtkWidget *object,gboolean toggle){
	gtk_editable_set_editable( GTK_EDITABLE(object),toggle );
	/*set specific gravity / factor as editable/uneditable*/
}/*END FUNCTION : */
/********************************************************************/
gdouble returnLengthWidthFormula(gdouble length,gdouble width,const gchar *cut){
	gboolean usesAvD=usesAvDiametersquared(cut);
	gdouble r,tmp;
	gpointer *data=NULL;
	gchar *avDiaString;/*prints to statusbar*/
	/*if((strcmp(cut,DIAROUND)==0) ||(strcmp(cut,DIATAPBAG)==0) ||
(strcmp(cut,DIAOVALCUT)==0) || (strcmp(cut,DIAOLDEURO)==0) ||
(strcmp(cut,DIAOLDMINE)==0) || (strcmp(cut,DIAROSE)==0) || (strcmp(cut,GEMOVAL)==0))*/
	if(usesAvD)
	{
		/*Tapered baguette Length x (max width + min width)/2 x depth x.00915
Old European Cut: Average diameter x depth x.0067 = Estimated Weight.
Old Mine Cut: Average diameter x depth x.0070 to .0072 = Estimated Weight.
Rose Cut: diameter2 x depth x.0074 (assuming a total depth of approximately 34%*/
		tmp=(width+length)/2;
		r=tmp*tmp;
		avDiaString=g_strdup_printf("using average diameter/length width :: %4.2f",tmp);
		g->delsbid=gtk_statusbar_push (GTK_STATUSBAR (g->statusbar ), GPOINTER_TO_INT (data), avDiaString);
	}else{
		r=length*width;
		avDiaString=g_strdup_printf("using length x width :: %4.2f x %4.2f",length,width);
		g->delsbid=gtk_statusbar_push (GTK_STATUSBAR (g->statusbar ), GPOINTER_TO_INT (data), avDiaString);
	}
	if((strcmp(cut,ROUNDBEAD)==0)){
		tmp=(width+length)/2;
		r=tmp*tmp*tmp;
		gtk_entry_set_text(GTK_ENTRY(g->entryd), "");
		/*blank out the depth field overridden in function resultGenerator?*/
	}
	g_free(avDiaString);
	return r;
}/*END FUNCTION : */
/********************************************************************/
gboolean AreSame(double a, double b)
{
	return fabs(a - b) < EPSILON;
}/*END FUNCTION : */
/********************************************************************/
gboolean toggle_button_callback (GtkWidget *widget, gpointer data)
{
	if (GTK_TOGGLE_BUTTON (widget)->active)
	{
		/*g_print("If control reaches here, the toggle button is down \n");*/
		return TRUE;
	} else {
		/*g_print("If control reaches here, the toggle button is up \n");*/
		return FALSE;
	}
}/*END FUNCTION : */
/********************************************************************/
void on_entryCUT_changed(GtkWidget *widget, gpointer data)
{
	/*
	 * if(firstRun!=FALSE){
	 * Calculate(g->entryCUT,NULL);
	 * g_print("called Calculate(g->entryCUT,NULL); from line %i\n",__LINE__);
	 * }
	 * 
	 */
	gchar **cutImageName;
	cutImageName=lookupCut(gtk_entry_get_text(GTK_ENTRY(g->entryCUT)),isDiamond);
	print_CUT_IMAGE((void**)cutImageName);
	if(isDiamond==TRUE)
		print_GEM_IMAGE_PIX(diamr_xpm);
	else
		if(gtk_entry_get_text_length(GTK_ENTRY(g->entryGEM))==0)print_GEM_IMAGE_PIX(gemr_xpm);
}/*END FUNCTION : */
/********************************************************************/
gchar **lookupCut(const gchar *c,gboolean D){
	gchar **returnC;
	Cuts *ListOfCuts;
	Cuts *a;
	/*returns the name of the cut to print*/
	gint lengthOfInputText=strlen(c)+1;
	gchar trimmedText[lengthOfInputText];
	strcpy(trimmedText,c);
	g_strstrip(trimmedText);
	if(D==TRUE){
		a=DiaCut_list;
		/*ListOfCuts=DiamondCuts;*/
	}else{
		a=GemCut_list;
		/*ListOfCuts=GemCuts;*/
	}
	returnC=noimage_c;
	for(ListOfCuts=a;ListOfCuts && ListOfCuts->cut; ListOfCuts++) {
		if(strcmp(ListOfCuts->cut,trimmedText)==0){
			returnC=ListOfCuts->image;
			break;
			/*break; we found a match. Let's get out of here*/
		}
	}
	return returnC;
}/*END FUNCTION : */
/********************************************************************/
gboolean checkManOverideStatus(){
	return gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (g->manoverideFCB));
	/*note:: sg is not reset and stays at the custom input value. presumably the user will notice this*/
}/*END FUNCTION : */
/********************************************************************/
void make_radios(void){
	GtkWidget *button;
	GtkWidget *separator;
	GtkWidget *horizontal_box;
	radio_button_DIA= gtk_radio_button_new_with_label( NULL, "Diamond" );
	radio_button_GEM= gtk_radio_button_new_with_label_from_widget( GTK_RADIO_BUTTON( radio_button_DIA ), "Gemstone" );
	horizontal_box= gtk_hbox_new( TRUE, 10 );
	separator = gtk_vseparator_new ();
	gtk_box_pack_start( GTK_BOX( horizontal_box ),radio_button_GEM , FALSE, FALSE, 50);
	gtk_box_pack_start (GTK_BOX (horizontal_box), separator, FALSE, FALSE, 0);
	gtk_box_pack_start( GTK_BOX( horizontal_box ),radio_button_DIA, FALSE, FALSE, 50 );
	gtk_container_add( GTK_CONTAINER( g->hboxT ), horizontal_box );
	gtk_widget_show_all( GTK_WIDGET( g->hboxT ) );
	gtk_widget_set_sensitive(g->entryGEM, FALSE);/*grey out diamond/gem entry box*/
	gtk_widget_set_sensitive(g->clearGB, FALSE);/*grey out diamond/gem entry box*/
	button=radio_button_GEM;
	gtk_signal_connect( GTK_OBJECT( button ),"clicked",G_CALLBACK( radio_gemdia_sel_call_back ),( gpointer )radio_button_GEM );
}/*END FUNCTION : make radios*/
/********************************************************************/ 
void link_hook( GtkLinkButton *button,const gchar *link,gpointer data ){
	gchar *cmd = g_strconcat( URLPROGRAM, link, NULL );
	g_spawn_command_line_async( cmd, NULL );
	g_free( cmd );
}
/********************************************************************/ 
void make_url2Website(const gchar* label,const gchar *link,GtkWidget *send2,gpointer data){
	GtkWidget *button;
	GtkWidget *horizontal_box;
	button=gtk_link_button_new_with_label(link,label);
#ifndef WIN32 
	gtk_link_button_set_uri_hook( link_hook, NULL, NULL );
	/*LINUX*/
#endif
	/*COMMON CODE*/
	horizontal_box= gtk_hbox_new( TRUE, 10 );
	gtk_box_pack_start( GTK_BOX( horizontal_box ),button, FALSE, FALSE, 50 );
	gtk_container_add( GTK_CONTAINER( send2 ), horizontal_box );
	gtk_widget_show_all( GTK_WIDGET( send2 ) );
	/*END COMMON CODE*/
#ifdef WIN32
	gtk_signal_connect( GTK_OBJECT( button ),"clicked",G_CALLBACK( win32ShowURI ),( gpointer )data );
#endif
}/*END FUNCTION : make uri jump to web site*/
/********************************************************************/ 
gboolean win32ShowURI(gpointer data){
#ifdef WIN32
	gchar *param;/*url hyperlink sent to button object*/
	const gchar *idThroughLabel=gtk_button_get_label(GTK_BUTTON(data));/*what is the label we sent in?*/
	if(strcmp(idThroughLabel,WEBSITEBASE)==0){
		param=WEBSITEURL;
	}else{
		if(strcmp(idThroughLabel,URILVSTRING)==0)
		{
			param=URILV;
			/*the '=' in the url will be interepreted as a delimiter in the BAT file. Is re-constructed using %1=%2*/
		}else{
			param="error loding URL";
		}
	}//end 
	if(DEBUG==TRUE)g_print("param = %s\n",param);
	SHELLEXECUTEINFO ExecuteInfo;
	memset(&ExecuteInfo, 0, sizeof(ExecuteInfo));
	ExecuteInfo.cbSize = sizeof(ExecuteInfo);
	ExecuteInfo.fMask = 0; 
	ExecuteInfo.hwnd = 0; 
	ExecuteInfo.lpVerb = "open"; // Operation to perform
	ExecuteInfo.lpFile = RUNBROWSERVBS; // Application name
	ExecuteInfo.lpParameters = param; // Additional parameters
	ExecuteInfo.lpDirectory = 0; // Default directory
	ExecuteInfo.nShow = SW_SHOW;
	ExecuteInfo.hInstApp = 0;
	if(ShellExecuteEx(&ExecuteInfo) == FALSE){
		// Could not start application -> call 'GetLastError()'
		return 0;
	}else{
		return 1;
	}
#else
	return 1;
#endif
}/*END FUNCTION : */
/********************************************************************/ 
void gateway2_GEM(void)
{
	isDiamond=FALSE;
	resetGEM();
	const gchar *CutGLabel=DEFGENCUTLABEL;
	const gchar *GemGLabel=DEFGGLABEL;
	gpointer *data=NULL;
	gtk_label_set_markup(GTK_LABEL (g->labelCUTsel), CutGLabel);
	gtk_label_set_markup(GTK_LABEL (g->labelGEMsel), GemGLabel);
	gtk_entry_set_text(GTK_ENTRY (g->entryf), DEFGEMFACTOR);/*set default values for a gem oval cut*/
	gtk_entry_set_text(GTK_ENTRY (g->entryCUT), GEMOVAL);/*set default values for oval cut*/
	g->delsbid=gtk_statusbar_push (GTK_STATUSBAR (g->statusbar ), GPOINTER_TO_INT (data), GEMSTATUSBARMESS);
	Calculate(NULL,NULL);
}/*END FUNCTION : */
/********************************************************************/ 
void gateway2_DIA(void)
{
	isDiamond=TRUE;
	const gchar *CutDLabel=FIRSTRUNDEFDIACUTLABELMESS;
	const gchar *GemGLabel=DEFAULTDIALABELMESS;
	gpointer *data=NULL;
	resetDIA();
	g->delsbid=gtk_statusbar_push (GTK_STATUSBAR (g->statusbar ), GPOINTER_TO_INT (data), DIASTATUSBARMESS);
	gtk_label_set_markup(GTK_LABEL (g->labelCUTsel), CutDLabel);
	gtk_label_set_markup(GTK_LABEL (g->labelGEMsel), GemGLabel);
	Calculate(NULL,NULL);
}/*END FUNCTION : */
/********************************************************************/ 
void resetDIA(void){
	print_GEM_IMAGE_PIX(diamr_xpm);
	gtk_entry_set_text(GTK_ENTRY(g->entryGEM),"");
	gtk_entry_set_text(GTK_ENTRY(g->entryCUT),DIAROUND);
	gtk_entry_set_text(GTK_ENTRY(g->entryf),DEFDIAFACTORT);
	gtk_widget_set_sensitive(g->entryGEM, FALSE);/*grey out diamond/gem entry box*/
	gtk_widget_set_sensitive(g->clearGB, FALSE);/*grey out diamond/gem entry box*/
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (radio_button_DIA), TRUE);
}/*END FUNCTION : */
/********************************************************************/ 
void resetGEM(void){
	/*print_GEM_IMAGE_PIX(gemr_xpm);*/
	gtk_widget_set_sensitive(g->entryGEM, TRUE);/*activate diamond/gem entry box*/ 
	gtk_widget_set_sensitive(g->clearGB, TRUE);/*activate diamond/gem entry box*/
}/*END FUNCTION : */
/********************************************************************/ 
gdouble returnDepthIfEmpty(gdouble w,gdouble percentage){
	return w*percentage;
}/*END FUNCTION : */
/********************************************************************/ 
gdouble returnAverage(gdouble l,gdouble w){
	return (l+w)/2;
}/*END FUNCTION : */
/********************************************************************/ 
gdouble retTaperedDiamondWidth(const gchar* w){
	gdouble MAX;
	gdouble MIN;
	gdouble width=0;
	gchar** arrayOfStrings;
	arrayOfStrings=g_strsplit(w,",",2);
	gint16 i;
	for(i=0;arrayOfStrings[i]!=NULL;++i){
		if(DEBUG==TRUE)g_print("arrayOfStrings[%d] = %s \n",i,arrayOfStrings[i]);
		if(i==0){
			sscanf(arrayOfStrings[i], "%lf",&MAX);/*convert length to double*/
		}
		if(i==1){
			sscanf(arrayOfStrings[i], "%lf",&MIN );/*convert length to double*/
		}
	} 
	g_strfreev(arrayOfStrings);
	if(i==1){
		width=MAX;
		/*g->delsbid=gtk_statusbar_push (GTK_STATUSBAR (g->statusbar ), GPOINTER_TO_INT (g->context_id), "Warning: Please enter a second value in width field (eg 4,3)");*/
		if(DEBUG==TRUE)g_print("MAX is %f\n",MAX);
	}
	if(i==2)width=((MIN+MAX)/2);
	return width;
}/*END FUNCTION : */
/********************************************************************/ 
void logRecutWeight(gdouble RW){
	/*global*/
	gchar *sRW=g_strdup_printf("%4.2f",RW);
	logRW=sRW;	
}/*END FUNCTION : */
/********************************************************************/ 
const gchar* returnRecutWeight(gdouble l,gdouble w,gdouble depth,const gchar *cText,gboolean showThous,gdouble actualWeight){
	//g_print("w,depth\n%f %f\n",w,depth);
	/* OLD CUT 
The diameter of the girdle is measured in various directions; this gives very uneven results, especially in the case of square-round shapes. Then the smallest diameter in millimeters is selected.
This smallest diameter = 100 %.
The maximal allowable total height of 62 % is then calculated to avoid unnecessary loss of weight and to use as much as possible of the existing "diamond material" of the old-cut.
The formula for calculating the new height is:
Height = R Ø (smallest Value) X 0.62
The result shows the total height in millimeters of the new brilliant after re-cutting.
Taking this calculated height and the measured smallest girdle diameter the weight can be estimated according to the following formula:
carat weight = height(new) x R Ø2 X 0.0061
In the case of a square-round diameter, the loss in weight is about 20-30 %, in the case of brilliants with constant diameter about 5-15 %.
In the case of old-cuts where. the total height is definitely too low (under 54 %), the girdle diameter must be decreased in order to achieve ideal proportions between the total height and the girdle diameter.
A new girdle diameter must be established:
The total height is measured in millimeters. The height is taken as = 58 %.
A small percentage value recommended for a "very good" cut is selected so that the girdle does not have to be reduced too much in order to save weight. The girdle diameter of 100 % is calculated according to the following formula:
R Ø = height x 100/58
Taking the measured total height and the calculated girdle diameter the weight can be arrived at using the known formula:
carat weight = height x R Ø2 X 0.0061
In the case of a brilliant with square-round base the loss of weight is about 30-40 %, where the shape is more circular about 10-20 %.
	 */
	if((w == ZERO && depth==ZERO) || depth<ZERO){
		print_RECUTIMAGE_PIX(noimage_c," "," ");/*reset recut image*/
		return "<span foreground=\"red\"><i>Warning!</i>:: Invalid Input\nCannot Calculate Recut Estimation</span>";
	}else{
		gdouble newDepth=depth;
		gdouble newDiameter=w;
		gdouble caratLoss;
		gdouble caratLossPerc;
		gdouble ShallowStone;
		gdouble DeepStone;
		gdouble *p;
		gdouble recutWeight=0;
		gdouble newDepthPercentage=0;
		const gchar *tooltipString;
		const gchar *cutLegendLabel;
		/*****************************/
		const guint16 lowThreshold=55;/*ie threshold is 54%*/
		const guint16 highThreshold=62;/*ie threshold is 62%*/
		/*****************************/
		gdouble depthpercentage=depthPercentage(depth,w);/*get original depth percentage*/
		guint16 dpCompareWithThreshold=(guint16)depthpercentage;/*cast*/
		//g_print("dpCompareWithThreshold %d\n",dpCompareWithThreshold);
		tooltipString=g_strdup_printf("Depth Percentage%4.0f%% falls within %d and %d",depthpercentage,lowThreshold,highThreshold);
		cutLegendLabel=g_strdup_printf("No Recut:: %4.0f%%",depthpercentage);
		print_RECUTIMAGE_PIX(noimage_c,tooltipString,cutLegendLabel);/*reset image*/
		/*****************************/
		DeepStone=(w*62)/100;
		ShallowStone=(depth*100)/58;
		/*****************************/
		if(strcmp(cText,DIAOVALCUT)==0 || strcmp(cText,DIAROUND)==0 || strcmp(cText,DIAOLDMINE)==0 || strcmp(cText,DIAOLDEURO)==0){
			print_RECUTIMAGE_PIX(noRecut_c,tooltipString,cutLegendLabel);
			if(dpCompareWithThreshold < lowThreshold){/*it's a shallow stone*/
				p=&ShallowStone;
				newDiameter=*p;
				tooltipString="shallow stone";
				print_RECUTIMAGE_PIX(shallow,tooltipString,tooltipString);
			}
			if(dpCompareWithThreshold > highThreshold){/*it's a deep stone*/
				tooltipString="deep stone";
				p=&DeepStone;
				newDepth=*p;
				print_RECUTIMAGE_PIX(deep,tooltipString,tooltipString);
			}
			recutWeight=(newDiameter*newDiameter)*newDepth*DEFDIAFACTOR;
			/*sent to external variable for logging*/
			logRecutWeight(recutWeight);
			//logRW=NULL;/*reset*/
			caratLoss=actualWeight-recutWeight;
			caratLossPerc=100*((actualWeight-recutWeight)/actualWeight);
			newDepthPercentage=depthPercentage(newDepth,newDiameter);
			if(showThous==TRUE){
				return g_strdup_printf("<small>New Diameter (original %4.2f) >> %4.2f\nNew Depth (original %4.2f) >> %4.2f\nNew Depth Percentage=%4.2f%%\nCarat weight loss = %4.2fct\nWeight loss Percentage = %4.2f%%</small>\n<span foreground=\"blue\">Recut Estimation :<b>%4.3f</b>ct</span>",w,newDiameter,depth,newDepth,newDepthPercentage,caratLoss,caratLossPerc,recutWeight);
			}else{
				return g_strdup_printf("<small>New Diameter (original %4.2f) >> %4.2f\nNew Depth (original %4.2f) >> %4.2f\nNew Depth Percentage=%4.2f%%\nCarat weight loss = %4.2fct\nWeight loss Percentage = %4.2f%%</small>\n<span foreground=\"blue\">Recut Estimation :<b>%4.2f</b>ct</span>",w,newDiameter,depth,newDepth,newDepthPercentage,caratLoss,caratLossPerc,recutWeight);
			}//end thousands of a carat formatting
		}else{/*not DIAROUND DIAOLDMINE DIAOLDEURO*/
			//gtk_widget_hide(GTK_WIDGET(g->hboxRecutContainer));
			tooltipString=g_strdup_printf("Recut estimate not available for %s",cText);
			cutLegendLabel="n\\a";
			print_RECUTIMAGE_PIX(noRecut_na_c,tooltipString,cutLegendLabel);
			return g_strdup_printf("<small><span foreground=\"red\">Recut estimate not available for <i>%s</i></span></small>",cText);
		}//end ELSE for strcmp(cText,DIAROUND)==0 || strcmp(cText,DIAOLDMINE)==0 || strcmp(cText,DIAOLDEURO)==
	}//end not ZERO ELSE
}/*END FUNCTION : */
/********************************************************************/ 
void save_preferences(void){
	const gchar *thresholdvalue;
	gboolean enablLogging;
	thresholdvalue=gtk_entry_get_text(GTK_ENTRY(g->entryPrefThresh));
	/*gtk_entry_set_text(GTK_ENTRY(g->entryb),thresholdvalue);
	convert to gdouble and send to thousandsThreshold global*/
	enablLogging=toggle_button_callback(g->CBEnablLogging,NULL);
	thousandsThreshold=g_ascii_strtod(thresholdvalue,NULL);
	use1000thcarat=toggle_button_callback(g->CBDecPlace,NULL);
	gchar *m=(use1000thcarat==TRUE)?"using 1000th carat over 3.0mm":"DEFAULT: using 100th carat for stones over 3.0mm";
	showRecut=toggle_button_callback(g->CBRecut,NULL);

#ifdef WIN32
	update_preferences_bool_WIN32("showrecut",showRecut);
	update_preferences_bool_WIN32("showthou",use1000thcarat);
	update_preferences_bool_WIN32("enablelogging",enablLogging);
	update_preferences_string_WIN32("setthouthresh",thresholdvalue);
	//g_print("strings updated %s\n",__FUNCTION__);
#endif
	Calculate(NULL,NULL);/*recalculate after having updated preferences*/
	g->delsbid=gtk_statusbar_push (GTK_STATUSBAR (g->statusbar ), GPOINTER_TO_INT (g->context_id), m);
}/*END FUNCTION : */
/********************************************************************/
void check_config_file_exists_WIN32(const gchar *f)
{
	FILE * configuration_file;
	int length_of_output;
	/*DEFAULT VALUES*/
	gchar *new_conf_values=g_strdup_printf("\
			# Settings for Gemwest\n\
			[settings]\n\
			name=%s\n\
			showrecut=false\n\
			showthou=false\n\
			enablelogging=false\n\
			setthouthresh=%4.2f\n\
			",PROGRAM_NAME,THOUSANDSTHRESH);
	//~ if (fopen(configFile,"r")==NULL)  
	if (!g_file_test(CONFF, G_FILE_TEST_EXISTS)) {
		g_print("\nfile %s was not found (re-created)!\n",f);
		length_of_output=strlen(new_conf_values);
		configuration_file = g_fopen (CONFF, "w");
		fwrite(new_conf_values,1,length_of_output,configuration_file);
		fclose(configuration_file);
	}
}/*END FUNCTION : */
/********************************************************************/ 
void configuration_apply_settings(void){
}/*END FUNCTION : */
/********************************************************************/ 
void clear_log_file(const gchar *filename){
	//~ info_message(filename);
	//~ FILE *log_path;	
	GError *err=NULL;
	gchar *str;
	str=" ";
	gboolean result;
	while (gtk_events_pending()) gtk_main_iteration();
	/* set the contents of the file to the text from the buffer */
	//~ if (filename != NULL) {
	result = g_file_set_contents ((gchar*)filename, str, -1, &err);
	if(result==TRUE){
		info_message("Log File contents cleared!");
	}else{
		error_message("Log File not found\nNew File re-created");
		FILE *log_path;
		log_path = g_fopen (filename, "w");
		fwrite(" ",1,1,log_path);
		fclose(log_path);
	}
	//g_free(str); crashes app?????????????
}/*END FUNCTION : */
/********************************************************************/ 
void update_preferences_bool_WIN32(const gchar *var,gboolean value){
	FILE * configuration_file;
	GKeyFile *keyfile;
	gchar *output;
	GError *error;
	int length_of_output;
	GKeyFileFlags flags;
	gsize Slength;
	keyfile = g_key_file_new ();
	flags = G_KEY_FILE_KEEP_COMMENTS | G_KEY_FILE_KEEP_TRANSLATIONS;
	if (!g_key_file_load_from_file (keyfile,CONFF, flags, &error))
	{
		//~ warning_message(CONFF);
		g_print("path is not found>> %s\n",CONFF);
	}else{
		g_key_file_set_boolean(keyfile,"settings",var,value);
		output=g_key_file_to_data(keyfile,&Slength,&error);
		length_of_output=strlen(output);
		configuration_file = g_fopen (CONFF, "w");
		//~ if(configuration_file== NULL) {
		if (!g_file_test(CONFF, G_FILE_TEST_EXISTS)) {
			perror("failed to open configuration_file\nrebuilt directory and conf file\n");
			//return -1;
		}
		fwrite(output,1,length_of_output,configuration_file); 
		fclose(configuration_file);
	}
}/*END FUNCTION:*/
/********************************************************************/ 
const gchar *OLD_return_windows_path_name(const gchar* myfile){
	const gchar *filewin=NULL;
#ifdef WIN32
	gchar *path;
	const gchar *pathwin;

	pathwin=INSTALLTOBASEDIR;/*seems to be issues getting write permissions in g_get_user_cache_dir in WIN7*/
	path = g_build_filename (pathwin, BASEAPP, NULL);
	g_mkdir_with_parents (path, 0777);
	filewin = g_strconcat(path, G_DIR_SEPARATOR_S, myfile, NULL);
#endif
	return filewin;
}
/********************************************************************/
const gchar *return_unix_log_path(void){
	const gchar * cachepath;
	gchar *cpath;
	cachepath=g_get_user_cache_dir ();
	cpath = g_build_filename (cachepath, BASEAPP, NULL);
	g_mkdir_with_parents (cpath, 0777);
	return cachepath = g_strconcat(cpath, G_DIR_SEPARATOR_S, UNIXLOGFILE, NULL);
}/*END FUNCTION : */
/********************************************************************/
void loadPreferences(){
	//~ OLD_LOGTXTFILEWIN	is "log.txt"
	gboolean getStateRecutOn=0;
	gboolean getStateShowThou=0;
	gboolean getStateLogging=0;
	const gchar *getStateEntryPrefThresh;
#ifdef WIN32

	/*CREATE CONF FILE*/
	check_config_file_exists_WIN32(CONFF);
	GKeyFile *keyfile;
	GError *error=NULL;
	GKeyFileFlags flags;
	/* Create a new GKeyFile object and a bitwise list of flags. */
	keyfile = g_key_file_new ();
	flags = G_KEY_FILE_KEEP_COMMENTS | G_KEY_FILE_KEEP_TRANSLATIONS;
	/* Load the GKeyFile from keyfile.conf or return. */
	if (!g_key_file_load_from_file (keyfile,CONFF, flags, &error))
	{
		/*hope we don't get here Should be picked up with check_config_file_exists_WIN32(CONFF)!*/
		gchar *e=g_strdup_printf("Your Conf file failed to load in \n%s\nPlease check location is writable",CONFF);
		error_message (e);
	}
	getStateRecutOn = g_key_file_get_boolean(keyfile, "settings","showrecut",NULL) ;
	getStateShowThou =g_key_file_get_boolean(keyfile, "settings","showthou",NULL);
	getStateLogging =g_key_file_get_boolean(keyfile, "settings","enablelogging",NULL);
	getStateEntryPrefThresh = g_key_file_get_string(keyfile, "settings","setthouthresh", NULL);
	/*CREATE LOG FILE*/
	FILE *log_path;
	if (!g_file_test(LOGF_WIN, G_FILE_TEST_EXISTS)) {
		log_path = g_fopen (LOGF_WIN, "w");
		fwrite("LOG",1,1,log_path);
		fclose(log_path);
		LOGPATH=LOGF_WIN;

	}
	LOGPATH=LOGF_WIN;
#endif

#ifdef unix
	GConfClient *config;
	config = gconf_client_get_default ();
	getStateRecutOn = gconf_client_get_bool (config, "/apps/gemwest/showrecut", NULL);
	getStateShowThou = gconf_client_get_bool (config, "/apps/gemwest/showthou", NULL);
	getStateLogging = gconf_client_get_bool (config, "/apps/gemwest/enablelogging", NULL);
	getStateEntryPrefThresh = gconf_client_get_string (config, "/apps/gemwest/setthouthresh", NULL);
	LOGPATH = return_unix_log_path();
	/*UNIX!!*/
#endif
	/********************adjust GUI******************************/
	if(getStateRecutOn==TRUE){
		gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON (g->CBRecut),TRUE);/*unset recut button*/
	}else{
		gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON (g->CBRecut),FALSE);/*set recut button*/
	}
	/**/
	if(getStateShowThou==TRUE){
		gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON (g->CBDecPlace),TRUE);/*unset recut button*/
	}else{
		gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON (g->CBDecPlace),FALSE);/*set recut button*/
	}
	/**/
	if(getStateLogging==TRUE){
		gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON (g->CBEnablLogging),TRUE);/*unset recut button*/
	}else{
		gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON (g->CBEnablLogging),FALSE);/*set recut button*/
	}
	/**/
	if(getStateEntryPrefThresh!=NULL)
		gtk_entry_set_text(GTK_ENTRY(g->entryPrefThresh),getStateEntryPrefThresh);
	save_preferences();
}/*END FUNCTION : */
/********************************************************************/
void error_message (const gchar *message)
{
	GtkWidget *dialog;
	/* log to terminal window */
	g_warning ("%s",message);
	/* create an error message dialog and display modally to the user */
	dialog = gtk_message_dialog_new (NULL, 
			GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
			GTK_MESSAGE_ERROR,
			GTK_BUTTONS_OK,"%s",
			message);
	gtk_window_set_title (GTK_WINDOW (dialog), "Error!");
	gtk_dialog_run (GTK_DIALOG (dialog)); 
	gtk_widget_destroy (dialog); 
}/*END FUNCTION : */
/********************************************************************/ 
gint question_message (const gchar *message)
{
	/*continue delete all LOGPATH reference create new open not open*/
	gint result;
	GtkWidget *dialog;
	/* log to terminal window */
	g_warning ("%s",message);
	/* create an error message dialog and display modally to the user */
	dialog = gtk_message_dialog_new (NULL, 
			GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
			GTK_MESSAGE_QUESTION,
			GTK_BUTTONS_YES_NO,"%s",
			message);
	gtk_window_set_title (GTK_WINDOW (dialog), "Question!");
	//gtk_dialog_run (GTK_DIALOG (dialog)); 
	result = gtk_dialog_run (GTK_DIALOG (dialog));
	/*g_print("\n\tresult = %d\n",result);*/
	if (result == GTK_RESPONSE_YES){
		/* Yes was clicked;*/
		//~ g_print("/* Yes was clicked */");
	}
	//return result;
	gtk_widget_destroy (dialog);
	return result; 
}/*END FUNCTION : */
/********************************************************************/ 
void info_message (const gchar *message)
{
	GtkWidget *dialog;
	/* log to terminal window */
	g_warning ("%s",message);
	/* create an error message dialog and display modally to the user */
	dialog = gtk_message_dialog_new (NULL, 
			GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
			GTK_MESSAGE_INFO,
			GTK_BUTTONS_OK,"%s",
			message);
	gtk_window_set_transient_for(GTK_WINDOW (dialog),GTK_WINDOW (g->window));
	gtk_window_set_title (GTK_WINDOW (dialog), "Info");
	gtk_dialog_run (GTK_DIALOG (dialog)); 
	gtk_widget_destroy (dialog); 
}/*END FUNCTION : */
/********************************************************************/ 
void warning_message (const gchar *message)
{
	GtkWidget *dialog;
	/* log to terminal window */
	g_warning ("%s",message);
	/* create an error message dialog and display modally to the user */
	dialog = gtk_message_dialog_new (NULL, 
			GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
			GTK_MESSAGE_WARNING,
			GTK_BUTTONS_CLOSE,"%s",
			message);
	gtk_window_set_title (GTK_WINDOW (dialog), "Warning!");
	gtk_dialog_run (GTK_DIALOG (dialog)); 
	gtk_widget_destroy (dialog); 
}/*END FUNCTION : */
/********************************************************************/ 
void update_preferences_string_WIN32(const gchar *var,const gchar *strng){
	FILE * conf_file;
	GKeyFile *keyfile;
	gchar *output;
	GError *error;
	int length_of_output;
	GKeyFileFlags flags;
	gsize Slength;
	keyfile = g_key_file_new ();
	flags = G_KEY_FILE_KEEP_COMMENTS | G_KEY_FILE_KEEP_TRANSLATIONS;
	/* Create a new GKeyFile object and a bitwise list of flags. */
	if (!g_key_file_load_from_file (keyfile,CONFF, flags, &error))
	{
		g_print("path is not found>> %s\n",CONFF);
	}else{
		g_key_file_set_string(keyfile,"settings",var,strng);
		output=g_key_file_to_data(keyfile,&Slength,&error);
		length_of_output=strlen(output);
		conf_file = g_fopen (CONFF, "w");
		if(conf_file== NULL) {
			perror("failed to open conf_file\nrebuilt directory and conf file\n");
			//return -1;
		}
		fwrite(output,1,length_of_output,conf_file); 
		if(DEBUG==TRUE){
			printf("fclose(conf_file) %s.\n", fclose(conf_file) == 0 ? "succeeded" : "failed");
		}else{
			fclose(conf_file);
		}
	}
}/*END FUNCTION : */
/********************************************************************/ 

void on_buttonRevertPref_clicked(GtkWidget *widget,gpointer data){
#ifdef unix
	GConfClient *config;
	/*******************SET GCONF*******************************/
	config = gconf_client_get_default ();
	gconf_client_set_bool (config, "/apps/gemwest/showrecut", FALSE, NULL);
	gconf_client_set_bool (config, "/apps/gemwest/showthou", FALSE, NULL);
	gconf_client_set_bool (config, "/apps/gemwest/enablelogging", FALSE, NULL);
	gconf_client_set_string (config, "/apps/gemwest/setthouthresh", g_strdup_printf("%4.2f",THOUSANDSTHRESH), NULL);
	gconf_client_unset(config,"/apps/gemwest/LogFile",NULL);
#endif
#ifdef WIN32
	update_preferences_bool_WIN32("showrecut",FALSE);
	update_preferences_bool_WIN32("showthou",FALSE);
	update_preferences_bool_WIN32("enablelogging",FALSE);
#endif
	gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON (g->CBRecut),FALSE);/*unset interpolate button*/
	gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON (g->CBDecPlace),FALSE);/*unset interpolate button*/
	gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON (g->CBEnablLogging),FALSE);/*unset interpolate button*/
	gtk_entry_set_text( GTK_ENTRY (g->entryPrefThresh),g_strdup_printf("%4.2f",THOUSANDSTHRESH));/*unset interpolate button*/
	//~ gtk_label_set_markup(GTK_LABEL(g->labelLogPath),g_strdup_printf("<small>Log:: n/a</small>"));	
}/*END FUNCTION : */
/********************************************************************/ 
void write2LogFile(const gchar *string, gdouble myAnswer){
	FILE * filename;
	int length_of_output;
	static gdouble compare;
	if(compare==ZERO && myAnswer==ZERO){
		//~ /*DIE SILENTLY IGNORE*/
	}else{
		if(myAnswer!=ZERO && compare!=myAnswer){
			gchar *str;
			if(logRW!=NULL)
				str=g_strdup_printf("%s %s :: %s (Recut: %s)\n",__DATE__,__TIME__,string,logRW);
			else
				str=g_strdup_printf("%s %s :: %s\n",__DATE__,__TIME__,string);
			filename = g_fopen (LOGPATH,"a");
			length_of_output=strlen(str);
			while (gtk_events_pending()) gtk_main_iteration();
			/* set the contents of the file to the text from the buffer */
			if (filename != NULL) 
				fwrite(str,1,length_of_output,filename);
			/* don't forget to free that memory! */ 
			g_free (str); 
			fclose(filename); 
		}else{/*end else*/
			if(DEBUG==TRUE)g_print(" NOT writing");
		}
	}//end comparez 
	compare=myAnswer;/*changes static variable with current result for comparing for next write*/
}/*END FUNCTION : */
/********************************************************************/ 
gchar* display_log(void){
	GError *err=NULL;
	//gchar *status;
	gchar *text=NULL;
	gboolean result;
	GtkTextBuffer *buffer;
	if(gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON (g->CBEnablLogging))==TRUE){	
		if (g_file_test(LOGPATH, G_FILE_TEST_EXISTS)) {
			result = g_file_get_contents (LOGPATH, &text, NULL, &err);
			printf("%s\n",text);
			if (result == FALSE)
			{
				/* error loading file, show message to user */
				error_message (err->message);
				g_error_free (err);
				//try to create a new file
				FILE *newlogfile;
				newlogfile = g_fopen (LOGPATH, "w");
				warning_message("line");
				fwrite("",1,1,newlogfile);
				fclose(newlogfile);
				info_message("Log File not found!\nNew log file created!\nPlease resubmit calculation");
			}/*END CANNOT FIND LOGFILE*/
			/* disable the text view while loading the buffer with the text */ 
			gtk_widget_set_sensitive (g->text_view, FALSE);
			if(gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON( g->CBEnablLogging) ) ){
				buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (g->text_view));
				gtk_text_buffer_set_text (buffer, text, -1);
				gtk_widget_set_sensitive (g->CBclear_log, TRUE);
				if(DEBUG==TRUE)g_print("\nshow text\n");
				gtk_widget_set_sensitive (g->text_view, TRUE);
			}else{
				buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (g->text_view));
				if(DEBUG==TRUE)g_print("\nhide text\n");
				gtk_text_buffer_set_text (buffer,"Logging disabled\nPlease enable in Preferences", -1);
				gtk_widget_set_sensitive (g->CBclear_log, FALSE);
			}
		} /*if (!g_file_test(LOGFILE, G_FILE_TEST_EXISTS)) {*/
	}//if(gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON (g->CBEnablLogging))==TRUE){	
	return text;
	g_free (text);

}/*END FUNCTION : */
/*************END FUNCTION DEFINITIONS******************/ 

