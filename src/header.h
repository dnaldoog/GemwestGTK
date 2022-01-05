#ifndef HEADER_H
#define HEADER_H
#ifdef unix
#define ICON_SOURCE PACKAGE_DATA_DIR "/pixmaps/gemwest.png"
#define BUILDER_XML_FILE "interface.glade"
#define XML2FILE 0 
#define URLPROGRAM "xdg-open "
/*
 * 
 * IF TRUE: glade interface will be compiled into executable (xml file still installs but is not loaded) RE: main.c
 * write glade_file.c with glade2string.py
 * 
 */
#elif defined WIN32 
#define INSTALLTO "C:/Program Files/gemwest"
#define INSTALLTOBASEDIR "C:/Program Files/"
#define ICON_SOURCE INSTALLTO "/gw128.ico"
/*#define BUILDER_XML_FILE INSTALLTO"/interfaceWIN.glade"*/
#define BUILDER_XML_FILE INSTALLTO "/interface.glade"
#define XML2FILE 0 
#define URLPROGRAM "cmd /c start "
/*
 * 
 * IF TRUE: glade interface will be compiled into executable 
 * (xml file still installs but is not loaded) RE: main.c
 * write glade_file.c with glade2string.py
 * 
 */
#endif
#define BASEAPP "gemwest"
#define LOGF_WIN "C:/Program Files/gemwest/log.txt" 
#define CONFF "C:/Program Files/gemwest/conf" 
#define UNIXLOGFILE "log.txt" /*name of file for logging (actual directory is determined by OS) DEFUNCT 1.00 unix*/
#define PROGRAM_NAME "Gemstone Weight Estimator"

#ifdef WIN32
#define VERSION "1.03"
#endif
/*#defined <VERSION "1.03"> for UNIX now in CONFIG_H*/

#define DEBUG 0 /*only used in development*/
#define DEFDGLABEL "Diamond"
#define DIAMOND DEFDGLABEL
#define DEFDCLABEL "Diamond Cut"
#define DEFGCLABEL GEMOVAL
#define DEFGEMFACTOR "0.0020"
#define DEFDIAFACTOR 0.0061
#define DEFDIAFACTORT "0.00610"
#define DEPTHPERCENTAGELOWERLIMIT 0
#define DEPTHPERCENTAGEUPPERLIMIT 101
#define DEFDIACUTLABELMESS "<span font_size='small'>Cut (Leave Blank for Round Brilliant)</span>"
#define DEFAULTDIALABELMESS "<span font_size='small'>Diamond</span>"
#define DEFGENCUTLABEL "<span font_size='small'>Gem Cut</span>"
#define DEFGGLABEL "<span font_size='small'>Gemstone</span>"
#define EPSILON 0.001 /*level of sensitivity for comparing double to zero truth*/
#define FANCYCOMPARESTRING "n/a"
#define FANCYDIAMARQUISE "marquise brilliant"
#define FANCYDIAEMERALD "emerald cut diamond"
#define FANCYDIAPEAR "pear brilliant"
#define DIAROUND "round brilliant"
#define DIATAPBAG "tapered baguette"
#define DIAOVALCUT "oval brilliant"
#define DIAOLDEURO "old european cut"
#define DIAOLDMINE "old mine cut"
#define DIAROSE "rose cut"
#define DIASTATUSBARMESS "Enter in name of Cut"
#define FIRSTRUNDEFDIACUTLABELMESS "<span font_size='small'>Diamond Cut</span>"
#define GEMOVAL "oval cut"
#define GEMCUTXPMARRAYLENGTH 44 /*array elements in gemstone XPM image second (x) figure + 3*/
#define GEMCUTXPMRGBOVERLAY 2 /*position of string to be overwrittenin gemstone XPM image*/
#define GEMSTATUSBARMESS "Enter in name of Gemstone and Cut"
#define ICON_PACKAGE PACKAGE_DATA_DIR "/" ICON_SOURCE
#define INITSTATUSBARMESS "Gemwest: Gemstone Weight Estimator"
#define MOMME 18.75 /*one momme = 3.75 gm * 5 = 18.75*/
#define PEARL "pearl"
#define ROUNDBEAD "round bead"
#define ROUNDBEADFACTOR "0.00259"
#define RUNBROWSERVBS "runBrowser.vbs "/*Win32 only VB file which silently loads BAT file (must include trailing space)*/
#define THOUSANDSTHRESH 3.0 /*default mm size in which 1000 cat is used - useful for smaller stones*/
#define URILV WEBSITEBASE"lv.php?v="VERSION
#define URILVSTRING "Check for New Version"
#define WEBSITEBASE "http://gemwest.sourceforge.net/"
#define WEBSITEURL WEBSITEBASE"?fromApp=true"
/********************************************************************************************/
typedef struct
{
	GtkWidget *window;
	GtkWidget *entryl;/*length*/
	GtkWidget *entryw;/*width*/
	GtkWidget *entryd;/*depth*/
	GtkWidget *entrys;/*Specific Gravity*/
	GtkWidget *entryf;/*factor*/
	GtkWidget *entryb;/*adjustment*/
	GtkWidget *entryBdialog;/*adjustment in popup*/
	GtkWidget *spinbuttonGIR;/*adjustment in popup*/
	GtkWidget *spinbuttonPAV;/*adjustment in popup*/
	GtkWidget *spinbuttonSHP;/*adjustment in popup*/
	GtkWidget *entryPrefThresh;/*threshold level for 1000s ct*/
	GtkWidget *hboxZ;/*zaniah logo in about field*/
	GtkWidget *hboxCUT_PLATE;/*Place legend of rbcd graphic here*/
	GtkWidget *imageDEF;/*Default RBCD image when program loads*/
	GtkWidget *logPREF;/*log display window*/
	GtkWidget *vboxIMAGEcont;/*Container for Cut and Gem Images*/
	GtkWidget *vboxLOG;/*Container for LOG FILE*/
	GtkWidget *buttonCloseLog;/*Closes log file retriggers log*/
	GtkWidget *CBclear_log;/*Clear for LOG FILE*/
	GtkWidget *confirmDeleteLog;/*Conform Delete Window?*/
	GtkWidget *hboxDP_IMAGE;/*Place legend of Depth Percentage graphic here*/
	GtkWidget *hboxCUT_IMAGE;/*Place legend of cuts' graphic here*/
	GtkWidget *hboxGEM_IMAGE; /*Place legend of gems' graphic here*/
	GtkWidget *hboxT; /*Manually add radio button here*/
	GtkWidget *hboxRB0; /*Manually add radio button here for recut selections*/
	GtkWidget *hboxRB1; /*Manually add radio button here for recut selections*/
	GtkWidget *hboxRB2; /*Manually add radio button here for recut selections*/
	GtkWidget *hboxRB3; /*Manually add radio button here for recut selections*/
	GtkWidget *hboxRecutLegend; /*Manually add recut legends*/
	GtkWidget *hboxRecutContainer; /*Container hbox object for Recut Image and results*/
	GtkWidget *labelRecutLabelling; /*Label object for Recut Image labelling*/
	GtkWidget *vboxRecut; /*Container hbox object for Recut Image and results*/
	GtkWidget *hboxURILV; /*Container hbox object for Check Latest Version URI*/
	GtkWidget *hboxWebsite; /*Website URL*/
	GtkWidget *labelFA;/*Full printed result*/
	GtkWidget *interpolateCB;/*interpolate checkbox*/
	GtkWidget *drawingarea1;/*interpolate checkbox*/
	GtkWidget *entryGEM;/*GEMS*/
	GtkWidget *labelGEMsel;/*selected Gem label*/
	GtkWidget *labelCUTsel;/*selected Cut label*/
	GtkWidget *labelLW;/*selected Cut label*/
	GtkWidget *labelLeqW;/*Length = Width Button label*/
	GtkWidget *labell;/*length label*/
	GtkWidget *labelw;/*width label*/
	GtkWidget *labelDP;/*selected Cut label*/
	GtkWidget *labelFactor;/*LabelFactor set red if LW over on fancy diamonds*/
	GtkWidget *labelLogPath;/*Prints the Log File Path*/
	GtkWidget *entryCUT;/*CUTS*/
	GtkEntryCompletion *completion;
	GtkListStore *model;
	GtkWidget *answer;/*calculated result*/
	GtkWidget *answerRecut;/*Recut result*/
	GtkWidget *statusbar;/*statusbar object*/
	GtkWidget *calculateB;/*calculate button*/
	GtkWidget *buttonLEQW;/*l field = width field*/
	GtkWidget *buttonADJ;/*Adjustment button*/
	GtkWidget *manoverideFCB;/*calculate button*/
	GtkWidget *clearGB;/*clear Gem selection*/
	GtkWidget *clearCB;/*clear Cut selection*/
	GtkWidget *CBDecPlace;/*PREFERENCE 1/100th ct*/
	GtkWidget *CBRecut;/*Show recut formulae/size for old cuts?*/
	GtkWidget *CBEnablLogging;/*Enable logging?*/
	GtkWidget *resetB;/*reset button*/
	GtkWidget *dialogPREF;/*preferences dialog*/
	guint statusbar_context_id;/*id for statusbar*/
	gint context_id;/*id for statusbar*/
	gint delsbid;/*delete statusbar message_id*/
	const char *sba2;/*statusbar message for last calculation*/
	GtkWidget *aboutdialog;/*about dialog*/
	GtkWidget *dialogH;/*help dialog*/
	GtkWidget *linkbutton1;/*help dialog*/
	GtkWidget *text_view;
} Content;
/********************************************************************************************
END STRUCT DEFINITIONS
 ********************************************************************************************/
Content *g;/*pointer to struct*/
GtkWidget *pwebURI;/*widgets for website link*/
GtkTextBuffer *buffer;/*widget for log file*/
const gchar *LOGPATH;/*GLOBAL configuration paths set in void loadPreferences() function on load*/
const gchar *my_glade_file;/*pointer to glade_file.c if needed when XML2FILE == TRUE*/
gboolean writetoSG(void);/*writes SG value to GTK_ENTRY g->entrysg*/
gboolean AreSame(double a, double b);/*compares gdouble against 0.00 ( uses EPSILON )*/
void reset2GemStandardCut(void);/*on select of non-diamond sets cut to round cut*/
void toggleEditableFactor(GtkWidget *widget,gpointer data);/*toggles factor field editable or not*/
void listGemCompletion(void);/*list all gems*/
void listCutCompletion(void);/*list all gems*/
void makeLogWidget(GtkWidget *widget);/*make a log gtk_text_view_new () widget*/
void toggleEntryEditable(GtkWidget *object,gboolean toggle);/*toggles SG/Factor field editable*/
void print_CUT_IMAGE(gpointer* cut2print);
void print_GEM_IMAGE_PIX(char** cut2print);
void print_ADJUST_XPM(void);
void print_RECUTIMAGE_PIX(char** cut2print,const gchar *toolTip,const gchar *labelling);
void print_DP_IMAGE_PIX(gdouble dp);
void print_GEM_IMAGE(const gchar* gemColorMask);
void make_radios(void);/*manually packs radio buttons to hboxT widget*/
void make_url2Website(const gchar* label,const gchar *link,GtkWidget *send2,gpointer data);
void loadPreferences();/*list all gems*/
void check_config_file_exists_WIN32(const gchar *file2check);
void clear_log_file(const gchar *configpath);
/*void delete_all_conf_and_log_files(void);*/
void write2LogFile(const gchar *string,gdouble myAnswer);
void update_preferences_bool_WIN32(const gchar *var,gboolean value);
void update_preferences_string_WIN32(const gchar *var,const gchar *string);
const gchar *DEF_return_full_conf_path_for_windows(void);
const gchar *OLD_return_windows_path_name(const gchar* myfile);
const gchar *return_full_log_path_for_all(void);
void save_preferences(void);
/*manually make URL to website in aboutdialog regular gtk_about_dialog_get_website(..) for Windows*/
#endif 
/* __HEADER_H__ */
