#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "pixmaps_c.h"
#include "pixmaps_s.h"
/*******************************************************************************************
START ENUM DEFINITIONS
 ********************************************************************************************/
typedef enum {
	GemStone_NAME = 0, GemStone_SG,GemStone_Colour
} GemStoneCol;
/********************************************************************************************/
typedef enum {
	Cut_NAME = 0, Cut_FACTOR, Cut_IMAGE, Cut_Roundness
} CutCol;
/********************************************************************************************
START STRUCT DEFINITIONS
 ********************************************************************************************/
typedef struct GemStone {
	gchar *name;
	gchar *specgrav;
	gchar *colorMask;
} GemStone;/*end struct declaration*/
/********************************************************************************************/
typedef struct Cuts {
	gchar *cut;
	gchar *factor;
	gchar **image;
	gboolean roundish;/*is is it a round stone? Used to change labelling*/
	gboolean useAvDiameter;/*does the cut require average diameter formulae?*/
} Cuts;
/********************************************************************************************/
typedef struct FancyDFactor {
	gdouble lwBarrier;
	gdouble fancyDFactor;
	/********************************************************************************************/
} FancyDFactor;/*end struct declaration*/
FancyDFactor Fancy_MARQ_FACTOR_list[]={
		{1.0,0.00565},
		{1.5,0.00580},
		{2.0,0.00585},
		{2.5,0.00595},
		{3.0,0.00600},
		{0,0}
};
FancyDFactor Fancy_EMER_FACTOR_list[]={
		{1.0,0.0080},
		{1.5,0.0092},
		{2.0,0.0100},
		{2.5,0.0106},
		{3.0,0.0110},
		{0,0}
};
FancyDFactor Fancy_PEAR_FACTOR_list[]={
		{1.0,0.00616},
		{1.5,0.00600},
		{2.0,0.00590},
		{2.5,0.00575},
		{3.0,0.00540},
		{0,0}
};

/*» Ferro-axinite, iron rich, lilac brown to black, specific gravity of 3.31
» Magnesio-axinite, magnesium rich, pale blue to gray, specific gravity of 3.18
» Manganaxinite, manganese rich, yellow-orange, specific gravity of 3.32
» Tinzenite, iron & manganese intermediate, yellow, specific gravity of 3.37
*/

GemStone GemStone_list[] = {
		{"agate","2.6",". c #F3B056"},
		{"albite","2.58",". c #E2B19B"},
		{"alexandrite","3.71",". c #D9D8D7"},
		{"almandine","4",". c #8E0152"},
		{"amazonite","2.56",". c #039190"},
		{"amber","1.08",". c #E0A20B"},
		{"amethyst","2.65",". c #8E088F"},
		{"andalusite","3.15",". c #958223"},
		{"apatite","3.2",". c #EDECEB"},
		{"aquamarine","2.69",". c #84C3C8"},
		{"aragonite","2.94",". c #992E02"},
		{"aventurine quartz","2.66",". c #439665"},
		{"aventurine","2.6",". c #439665"},
		{"axinite (Ferro-axinite)","3.31",". c #83582E"},
		{"azurite","3.8",". c #1C36C1"},
		{"bakelite","1.26",". c #000100"},
		{"benitoite","3.67",". c #6184A2"},
		{"beryl aquamarine","2.69",". c #84C3C8"},
		{"beryl colourless","2.7",". c #FFFFFF"},
		{"beryl heliodor","2.7",". c #FDEA45"},
		{"beryl morganite","2.7",". c #E2AEA4"},
		{"beryl","2.7",". c None"},
		{"beryl maxixe","2.7",". c #76BDFF"},
		{"blende","4.09",". c #None"},
		{"bloodstone","2.6",". c #184419"},
		{"blue topaz","3.53",". c #1679B0"},
		{"bonamite","4.35",". c #779887"},
		{"bowenite","2.59",". c #3F5807"},
		{"brazilianite","2.99",". c #A1B403"},
		{"calcite","2.71",". c #B7B5B8"},
		{"californite","3.3",". c #9DCB73"},
		{"carborundum","3.17",". c #3B3B45"},
		{"carnelian","2.64",". c #C73026"},
		{"cassiterite","6.9",". c #585858"},
		{"cat's eye chrysoberyl","3.71",". c #BBBD3F"},
		{"celluloid","1.38",". c None"},
		{"chalcedony agate","2.6",". c #BBBD3F"},
		{"chalcedony aventurine","2.6",". c #439665"},
		{"chalcedony carnelian","2.64",". c #C73026"},
		{"chalcedony heliotrope","2.6",". c #391D55"},
		{"chalcedony moss agate","2.6",". c #C73026"},
		{"chalcedony onyx","2.6",". c #000000"},
		{"chalcedony","2.61",". c None"},
		{"chrome diopside","3.3",". c #391D55"},
		{"chrysoberyl alexandrite","3.71",". c #D9D8D7"},
		{"chrysoberyl cat's eye","3.71",". c #BBBD3F"},
		{"chrysoberyl cymophane","3.71",". c #A5A183"},
		{"chrysoberyl","3.71",". c #A5A183"},
		{"chrysocolla","2.1",". c #00A1B2"},
		{"chrysoprase","2.6",". c #019125"},
		{"citrine","2.65",". c #F7FF55"},
		{"colourless beryl","2.7",". c None"},
		{"conch pearl","2.84",". c #D4CBC3"},
		{"copal resin","1.06",". c #D34015"},
		{"coral","2.68",". c #FA4C13"},
		{"cornelian","2.64",". c #882C10"},
		{"corundum ruby","3.99",". c #D01740"},
		{"corundum sapphire","3.99",". c #345DD1"},
		{"corundum synthetic","4",". c None"},
		{"corundum","4",". c #None"},
		{"crocidolite","2.66",". c #5C6F76"},
		{"cubic zirconia","5.80",". c #FFFFFF"},
		{"cymophane","3.71",". c #5C6F76"},
		{"cz","5.80",". c #FFFFFF"},
		{"danburite","3",". c #AD9A8B"},
		{"datolite","2.95",". c #EFF5C7"},
		{"demantoid","3.85",". c #1F6F19"},
		{"diamond","3.52",". c #FFFFFF"},
		{"diopside","3.29",". c #00CF07"},
		{"ekanite","3.28",". c #4F6010"},
		{"emerald (Gilson)","2.70",". c #0A7736"},
		{"emerald","2.71",". c #0A7736"},
		{"enstatite","3.27",". c #BD9F59"},
		{"epidote","3.4",". c #6C622C"},
		{"euclase","3.1",". c #9AA891"},
		{"fibrolite","3.25",". c #CBC189"},
		{"fire opal","2",". c #CE490E"},
		{"fluorite","3.18",". c #74689A"},
		{"garnet almandine","4",". c #8E0152"},
		{"garnet demantoid","3.85",". c #1F6F19"},
		{"garnet grossular (pure)","3.59",". c #B65824"},
		{"garnet hessonite","3.63",". c #F36708"},
		{"garnet (mali)","3.67",". c #ABA64B"},
		{"garnet pyrope","3.8",". c #7B0703"},
		{"garnet spessartine","4.16",". c #F37324"},
		{"garnet uvarovite","3.77",". c #346236"},
		{"garnet","4.00",". c #7B0703"},
		{"ggg","7.05",". c #FFFFFF"},
		{"glass","2.65",". c #FFFFFF"},
		{"golden beryl","2.7",". c #FBFEA8"},
		{"goshenite","2.7",". c #FFFFFF"},
		{"grossular garnet","3.59",". c #B65824"},
		{"grossular","3.59",". c #B65824"},
		{"grossular (pure)","3.59",". c #B65824"},
		{"haematite","5.1",". c #4E5F57"},
		{"hambergite","2.35",". c #7F7F7F"},
		{"heliodor","2.7",". c #C69D12"},
		{"hematite","5.1",". c #4E5F57"},
		{"hemimorphite","3.52",". c #05B2D2"},
		{"hessonite","3.63",". c #F36708"},
		{"hiddenite","3.18",". c #B3E1BD"},
		{"howlite","2.56",". c #CCCCCC"},
		{"idocrase","3.4",". c #4B900F"},
		{"imperial topaz","3.53",". c #F7AA2A"},
		{"iolite","2.63",". c #555BB3"},
		{"jadeite","3.33",". c #607B2A"},
		{"jasper","2.55",". c #C42A06"},
		{"jet","1.33",". c #000000"},
		{"kornerupine","3.32",". c #565977"},
		{"kunzite","3.18",". c #AF94A0"},
		{"kyanite","3.68",". c #325280"},
		{"lapis lazuli","2.8",". c #151974"},
		{"larimar","4.75",". c #4598A0"},
		{"lazulite","3.1",". c #2C3AB8"},
		{"lepidolite","2.8",". c #9B9EC9"},
		{"lithium niobate","4.64",". c #6F6F6F"},
		{"malachite","3.8",". c #23AE8A"},
		{"mali garnet","3.67",". c #ABA64B"},
		{"marcasite","4.9",". c #6F6F6F"},
		{"maw-sit-sit","3",". c #089745"},
		{"maxixe","2.71",". c #76BDFF"},
		{"moissanite","3.15",". c #FFFFFF"},
		{"morganite","2.7",". c #E2AEA4"},
		{"moss agate","2.6",". c #537469"},
		{"nephrite","3.00",". c #7B793C"},
		{"obsidian","2.5",". c #75674D"},
		{"odontolite","3.1",". c #2DB6AE"},
		{"onyx","2.6",". c #000000"},
		{"opal","2.15",". c #9DBEA3"},
		{"painite","4.01",". c #6F1E13"},
		{PEARL,"2.71",". c #D4CBC3"},
		{"periclase","3.59",". c #AAAD9C"},
		{"peridot","3.34",". c #508714"},
		{"phenakite","2.96",". c #FFFBEB"},
		{"pink beryl","2.7",". c #E2AEA4"},
		{"pink topaz","3.53",". c #F553CA"},
		{"pleonaste","3.8",". c #353C31"},
		{"porcelain","2.3",". c #FFFFFF"},
		{"prehnite","2.87",". c #92994D"},
		{"pseudophite","2.7",". c None"},
		{"pyrites","4.9",". c #A5914A"},
		{"pyrope","3.8",". c #7B0703"},
		{"quartz amethyst","2.65",". c #8E088F"},
		{"quartz aventurine","2.66",". c #439665"},
		{"quartz chalcedony","2.61",". c None"},
		{"quartz citrine","2.65",". c #00A1B2"},
		{"quartz","2.65",". c None"},
		{"rhodochrosite","3.6",". c #FA9DA8"},
		{"rhodonite","3.6",". c #FA9DA9"},
		{"ruby","3.99",". c #D01740"},
		{"rutile","4.25",". c #F0C65A"},
		{"sapphire","3.99",". c #345DD1"},
		{"sard","2.61",". c #9B1D0F"},
		{"scapolite","2.7",". c #AB6A7E"},
		{"scheelite","6.1",". c #FA9930"},
		{"schorl","3.06",". c #696A6C"},
		{"serpentine","2.6",". c #636A4B"},
		{"seraphinite","2.8",". c #8AA09D"},
		{"silica glass","2.21",". c None"},
		{"sinhalite","3.48",". c #7C6724"},
		{"smithsonite","4.35",". c #3E918B"},
		{"spessartine","4.16",". c #F37324"},
		{"sphalerite","4.09",". c #FC7B00"},
		{"sphene","3.53",". c #A2942C"},
		{"spinel synthetic","3.65",". c None"},
		{"spinel","3.65",". c None"},
		{"spodumene","3.18",". c #C3C37D"},
		{"strontium titanate","5.13",". c #FFFFFF"},
		{"sugilite","2.74",". c #791C8F"},
		{"synthetic corundum","4",". c #FFFFFF"},
		{"taaffeite","3.61",". c #B0A3B7"},
		{"tektite","2.4",". c #928072"},
		{"topaz","3.53",". c None"},
		{"tortoiseshell","1.29",". c #CC903B"},
		{"tourmaline Schorl","3.06",". c None"},
		{"tourmaline","3.06",". c #3E7C06"},
		{"turquoise","2.8",". c #2DB6AE"},
		{"uvarovite","3.77",". c #346236"},
		{"variscite","2.55",". c #2A9C69"},
		{"vivianite","2.6",". c #5E6665"},
		{"water opal","2",". c #4F80A1"},
		{"yttrium aluminate YAG","4.57",". c #FFFFFF"},
		{"zircon (metamict)","4",". c #FFFFFF"},
		{"zircon (normal)","4.69",". c #FFFFFF"},
		{"zirconia (cubic)","5.7",". c #FFFFFF"},
		{"zoisite","3.35",". c #841C4B"},

		{NULL,NULL}
};
GemStone *listAllGems;

/********************************************************************************************/

Cuts DiaCut_list[] = {
		{"asscher","0.00800",asscher_c,1,0},
		{"barion","0.00800",asscher_c,1,0},
		{"cushion brilliant","0.00815",cushion_c,0,0},
		{"eight cut","0.0061",round_c,1,1},
		{FANCYDIAEMERALD,FANCYCOMPARESTRING,emerald_c,0,0},
		{"heart brilliant","0.0059",heart_c,0,0},
		{"flanders cut (dia.)","0.007",asscher_c,1,0},
		{DIAOLDEURO,"0.0067",round_c,1,1},
		{DIAOLDMINE,"0.0071",oldmine_c,1,1},
		{FANCYDIAMARQUISE,FANCYCOMPARESTRING,marquise_c,0,0},
		{FANCYDIAPEAR,FANCYCOMPARESTRING,pear_c,0,0},
		{"princess brilliant","0.0082",princess_c,1,0},
		{DIAOVALCUT,"0.0062",oval_c,0,1},
		{DIAROUND,DEFDIAFACTORT,round_c,1,1},
		{DIAROSE,"0.0074",round_c,1,1},
		{"small baguette","0.00915",baguette_c,0,0},
		{"square cut (dia.)","0.0082",princess_c,1,0},
		{DIATAPBAG,"0.00915",tbaguette_c,0,0},
		{"semi circle cut (dia.)","0.0077",semicircle_c,0,0},
		{"square cut (dia.)","0.0082",princess_c,1,0},
		{"triangular cut (dia.)","0.0057",trilliant_c,0,0},
		{"radiant cut (dia.)","0.00800",asscher_c,1,0},
		{"trilliant cut (dia.)","0.0057",trilliant_c,0,0},
		{"trillion (rounded sides)","0.0059",rtrilliant_c,0,0},
		{NULL,NULL,NULL,0}
};

/********************************************************************************************/
Cuts GemCut_list[] = {
		{"briolette","0.0000",noimage_c,0,0},
		{"cabochon - regular","0.0028",oval_c,0,0},
		{"cabochon - high domed cabs","0.0026",oval_c,0,0},
		{"cabochon - low domed cabs","0.0029",oval_c,0,0},
		{"emerald cut","0.00245",emerald_c,0,0},
		{"heart","0.0021",heart_c,0,0},
		{"long rectangle","0.0026",rectangular_c,0,0},
		{"marquise","0.0016",marquise_c,0,0},
		{GEMOVAL,"0.002",oval_c,0,1},
		{"pear cut","0.00175",pear_c,0,0},
		{"square cut","0.0023",princess_c,1,0},
		{"square cushion","0.0018",squarecushion_c,1,0},
		{"square step cut","0.0023",asscher_c,1,0},
		{"square with cut corners","0.0024",asscher_c,1,0},
		{"round cut","0.0018",round_c,1,0},
		{ROUNDBEAD,ROUNDBEADFACTOR,round_c,1,0},
		{"rectangle","0.0026",rectangular_c,0,0},
		{"rectangle step cut","0.0025",emerald_c,0,0},
		{"rectangle with cut corners","0.0026",emerald_c,0,0},
		{"rectangular cushion","0.0022",rectcushion_c,0,0},
		{"triangle","0.0018",trilliant_c,0,0},
		{NULL,NULL,NULL,0}
};
/***************GLOBAL VARIABLES******************************************/
Cuts *DiamondCuts;
Cuts *GemCuts;
FancyDFactor *pSizeArray;/*pointer to fancy diamond cut structs*/
GtkWidget *zlogo;/*pointer to zaniah logo*/
GtkWidget *radio_button_DIA;/*pointer to radio buttons*/
GtkWidget *radio_button_GEM;/*pointer to radio buttons*/
GtkWidget *radio_button_GEM;/*pointer to radio buttons*/
GtkWidget *radio_button_OC;/*pointer to radio buttons*/
GtkWidget *radio_button_SCDP;/*Shallow Crown Deep Pavilion*/
GtkWidget *radio_button_SCSP;/*Shallow Crown Shallow Pavilion*/
GtkWidget *radio_button_HCDP;/*High Crown Shallow Pavilion*/
GtkWidget *toggleDIA2GEM;/*widgets for switching between Diamond and Gemstones*/
const gchar *initStatusBarMess=INITSTATUSBARMESS;
const gdouble ZERO=0.0000000;
gchar *myNewLogFile=NULL;/*global variable to hold log file*/
gchar *vbs_command;/*vbs command string passed to runBrowser.vbs (WIN32 only!) **available to Linux for debugging*/
gchar *logRW=NULL;/*vbs command string passed to runBrowser.vbs (WIN32 only!) **available to Linux for debugging*/
gdouble thousandsThreshold=THOUSANDSTHRESH;
gboolean isDiamond=1;/*TRUE for DIAMOND :: FALSE for GEM*/
gboolean usesAvDiamSQ=0;/*uses Average Diameter squared? or L + W/2??*/
gboolean firstRun=1;/*TRUE for first run of program :: switched in Calculate function*/
gboolean use1000thcarat=FALSE;/*use 100th ct in final calculation?*/
gboolean showRecut=FALSE;/*Show recut formulae??*/
//gboolean enablLogging=FALSE;/*whether to enable logging or not*/
gint debugCounter=0;
//GtkWidget *ntv;
/******************FUNCTIONS**********************************************/
GtkWidget *xpm_label_box( GtkWidget *parent,gchar *xpm_filename,gchar *label_text );
GdkPixbuf *returnNewGemXPM(const gchar *m);/*overwrites gem cut image with new color*/
GdkPixbuf *returnNewDPXPM(gint16 dp);/*places line in Depth Percentage image*/
gchar* display_log(void);/*displays value in widget text_view and returns text for writing in write2file*/
void logRecutWeight(gdouble RW);/*store recut weight in global variable logRW*/
const gchar* checkInputSGequalslistedSG(const gchar *inputText);
const gchar* returnRecutWeight(gdouble l,gdouble w,gdouble depth,const gchar *cutText,gboolean showThous,gdouble actualWeight);
const gchar *return_unix_log_path(void);/*unix log text path*/
/*return recut estimation on old cuts*/
//const gchar *log_file_answer(gdouble l,gdouble w,gdouble d,gdouble sg,const gchar* adj,gdouble f,const gchar *cut,const gchar *gem,const gchar *carats);/*prints working to log file*/
gchar **lookupCut(const gchar *c,gboolean D);/*returns the cut image*/
/*check if gem input string and sg match. If the user types in the whole string eg 'ruby' we need to update the sg*/
gdouble returnLengthWidthFormula(gdouble length,gdouble width,const gchar *cut);/*depending on cut calculation of L*W varies slightly*/
gdouble returnCorrectedFactor(gdouble factor,const gchar *cutT,gdouble lw_ratio,gboolean interpolate,int *data);/*adjusts the factor depending on cut and LWRatio*/
gdouble interpolateFancyFactor(gdouble LR,gdouble HR,gdouble LF,gdouble HF,gdouble input);/*interpolates factor for Fancy Cut Diamonds*/
gdouble returnFancyFactor(FancyDFactor *a,gdouble lw_ratio,gboolean Interpolate);/*returns the fancy diamond factor based on lw ratio and interpolates if necessary*/
gdouble resultGenerator(gdouble l,gdouble w,gdouble d,gdouble s,gdouble b,gdouble f,gdouble lw_ratio);/*runs L*W*D*SG*FACTOR*Bulge*/
gdouble depthPercentage(gdouble depth, gdouble width);/*returns the depth percentage*/
gdouble lwratio(gdouble length, gdouble width);/*returns the LW ratio*/
gdouble returnDepthIfEmpty(gdouble w,gdouble percentage);/*return a default depth if left empty*/
gdouble returnAverage(gdouble l,gdouble w);/*used for printing result to interface*/
gdouble retTaperedDiamondWidth(const gchar* widthText);/*if input is comma delimted returns Max + Min Width/2*/

gboolean checkManOverideStatus();/*returnCorrectedFactor() is only run if this returns FALSE*/
gboolean toggle_button_callback (GtkWidget *widget, gpointer data);/*checks if interpolated is toggles ON or OFF*/
gboolean usesAvDiametersquared(const gchar *Cut);/*do we need to use av Diameter2 or L * W2??*/
gboolean win32ShowURI(gpointer data);/*cluncky way of opening a browser window in windows withut having the CMD window flash*/
void Calculate(GtkWidget *widget,gpointer data);/*main calculate function*/
void place_Cut_Legend_in_help_file();/*places embedded cut legend graphic in help file preloaded in main*/
void updateGemImageIfUserEnteredWholeString(const gchar *inputText);
void showImageFields(gboolean show);/*toggles visibity of images of Cuts and Gems*/
void tooltip(GtkWidget *widget,const gchar *message);/*set tooltip dynamically*/
void radio_gemdia_sel_call_back( GtkRadioButton *rb );/*toggle radio buttons*/
void gateway2_DIA(void);/*start all DIA calculation interface operations*/
void gateway2_GEM(void);/*start all GEM calculation interface operations*/
void resetDIA(void);/*reset to DIA default*/
void resetGEM(void);/*reset to GEM default*/
void need_LW_or_Diameter_Labelling();/*label Length Width to Diameter depending on cut chosen*/
void link_hook( GtkLinkButton *button,const gchar *link,gpointer data );/*hook function to check for updates*/
void error_message (const gchar *message);
void info_message (const gchar *message);
void warning_message (const gchar *message);
gint question_message (const gchar *message);

/*********************CALLBACK FUNCTIONS********************************
 *                WINDOWS needs G_MODULE_EXPORT
 * ********************************************************************/
G_MODULE_EXPORT gboolean on_match_select_gemstone(GtkEntryCompletion *widget,GtkTreeModel *model,GtkTreeIter *iter,gpointer user_data);
G_MODULE_EXPORT gboolean on_match_select_cut(GtkEntryCompletion *widget,GtkTreeModel *model,GtkTreeIter *iter,gpointer user_data);
G_MODULE_EXPORT void on_interpolateCB_toggled(GtkWidget *widget,gpointer data);
G_MODULE_EXPORT void on_calculateB_clicked (GtkWidget *widget,gpointer data);/*main funcation to run calculator*/
G_MODULE_EXPORT void on_resetB_clicked(GtkWidget *widget,gpointer data);/*clear all fields*/
G_MODULE_EXPORT void on_entryCUT_changed(GtkWidget *widget, gpointer data);/*Run Calculate again*/
G_MODULE_EXPORT void on_entryGEM_activate(GtkWidget *widget, gpointer data);/*update Gem Color Image*/
G_MODULE_EXPORT void on_clearGB_clicked(GtkWidget *widget,gpointer data);/*clears the Gem stone selection field*/
G_MODULE_EXPORT void on_toggleDia2Gem_toggled(GtkWidget *widget,gpointer data);/*clears the Diamond stone selection field*/
G_MODULE_EXPORT void on_clearCB_clicked(GtkWidget *widget,gpointer data);/*clears the Cut selection field*/
G_MODULE_EXPORT void on_CBclear_log_clicked(GtkWidget *widget,gpointer data );/*clears the Log*/
G_MODULE_EXPORT void on_buttonLEQW_clicked(GtkWidget *widget,gpointer data);/*swaps Length and Width if Length > Width*/
G_MODULE_EXPORT void on_buttonADJ_clicked(GtkWidget *widget,gpointer data);/*opens dialog for adjustments*/
G_MODULE_EXPORT void on_buttonApplyBulgeDialog_clicked(GtkWidget *widget,gpointer data);/*opens dialog for adjustments*/
G_MODULE_EXPORT void on_buttonRevertPref_clicked(GtkWidget *widget,gpointer data);/*reset preferences*/
G_MODULE_EXPORT void on_savePREF_clicked(GtkWidget *widget,gpointer data);/*saves Preferences*/
G_MODULE_EXPORT void on_buttonADJClearAll_clicked(GtkWidget *widget,gpointer data);/*clears all adjustments to zero adjustments*/
G_MODULE_EXPORT void on_spinbuttonGIR_value_changed(GtkSpinButton *widget,gpointer data);/*adjustments spinbutton GIRDLE*/
G_MODULE_EXPORT void on_spinbuttonPAV_value_changed(GtkSpinButton *widget,gpointer data);/*adjustments spinbutton PAVILION*/
G_MODULE_EXPORT void on_spinbuttonSHP_value_changed(GtkSpinButton *widget,gpointer data);/*adjustments spinbutton SHAPE*/
G_MODULE_EXPORT void on_aboutdialog_show(GtkWidget *widget,gpointer data);/*show about dialog*/
G_MODULE_EXPORT void on_help_show(GtkWidget *widget,gpointer data);/*show help  dialog*/
G_MODULE_EXPORT void on_entryl_activate(GtkWidget *widget,gpointer data);/*flags first run as false*/
G_MODULE_EXPORT void on_linkbutton1_clicked(GtkWidget *widget,gpointer *data );/*link URL clicked*/
G_MODULE_EXPORT void on_CBRecut_toggled(GtkWidget *widget,gpointer data );/*when CB recut toggled*/
G_MODULE_EXPORT void on_CBDecPlace_toggled(GtkWidget *widget,gpointer data );/*when dec place toggled*/
G_MODULE_EXPORT void on_CBEnablLogging_toggled(GtkWidget *widget,gpointer data );/*when logging enabled*/
G_MODULE_EXPORT void on_entryPrefThresh_changed(GtkWidget *widget,gpointer data );/*when threshold 100th carat entry changed*/
G_MODULE_EXPORT void on_MlLog_activate_item(GtkWidget *widget,gpointer data );/*load log file when view/log clicked*/
G_MODULE_EXPORT void on_buttonCloseLog_clicked(GtkWidget *widget,gpointer data );/*re-load log file when clicked*/
G_MODULE_EXPORT void on_buttonDELLOG_clicked(GtkWidget *widget,gpointer data );/*Clear LOG FILE*/
G_MODULE_EXPORT void on_buttonCopy2C(GtkWidget *widget,gpointer data );/*Copy LOG FILE to clipboard*/
//G_MODULE_EXPORT void on_checkbuttonDELALLCONF_toggled(GtkWidget *widget,gpointer data );/*Warning you are about to delete conf files*/

/********************************************************************
 * *
 * *
 * *
 ********************************************************************/
#endif 
