#include <stdio.h>
#include <gtk/gtk.h>
#include <conio.h>

GtkWidget *win, *vbox, *vbox1, *vbox2;
GtkWidget *window, *name_label, *grid, *storebutton, *name_entry, *age_label, *age_entry, *dob_label, *dob_entry;
GtkWidget *new_stud;
GtkWidget *aadhaar_entry,*aadhaar_label;
GtkWidget *phone_label, *phone_entry;
GtkWidget *email_label, *email_entry;
GtkWidget *father_name_label, *father_name_entry;
GtkWidget *fphone_label, *fphone_entry, *femail_label, *femail_entry;
GtkWidget *mother_name_label, *mother_name_entry;
GtkWidget *mphone_label, *mphone_entry, *memail_label, *memail_entry;
GtkWidget *caddress_label, *caddress_entry, *paddress_label, *paddress_entry;
GtkWidget *search_stud, *sbox, *tos_entry, *s_button;
GtkWidget *ebox, *delbox, *del_label, *del_entry, *del_btn;

struct stud
{
    char name[30];
    char age[3];
    char dob[10];
    char aadhaar[12];
    char stph[10];
    char stmail[100];
    char fathername[30];
    char fatherphone[10];
    char fathermail[30];
    char mothername[30];
    char motherphone[10];
    char mothermail[30];
    char stcurraddress[100];
    char stperaddress[100];
};

void sortname()
{
	int i=0;
	struct stud s[100];
	FILE *fp=fopen("student.csv","r");
	char line[100];
	fgets(line,100,fp);//extracting the first header
	while(fgets(line,100,fp)!=NULL)
	{
		char *name=strtok(line,",");
		strcpy(s[i].name,name);
		char *age=strtok(NULL,",");
		strcpy(s[i].age,age);
		char *dob=strtok(NULL,",");
		strcpy(s[i].dob,dob);
		char *aadhaar=strtok(NULL,",");
		strcpy(s[i].aadhaar,aadhaar);
		char *stph=strtok(NULL,",");
		strcpy(s[i].stph,stph);
		char *stmail=strtok(NULL,",");
		strcpy(s[i].stmail,stmail);
		char *fathername=strtok(NULL,",");
		strcpy(s[i].fathername,fathername);
		char *fatherphone=strtok(NULL,",");
		strcpy(s[i].fatherphone,fatherphone);
		char *fathermail=strtok(NULL,",");
		strcpy(s[i].fathermail,fathermail);
		char *mothername=strtok(NULL,",");
		strcpy(s[i].mothername,mothername);
		char *motherphone=strtok(NULL,",");
		strcpy(s[i].motherphone,motherphone);
		char *mothermail=strtok(NULL,",");
		strcpy(s[i].mothermail,mothermail);
		char *stcurraddress=strtok(NULL,",");
		strcpy(s[i].stcurraddress,stcurraddress);
		char *stperaddress=strtok(NULL,",");
		strcpy(s[i].stperaddress,stperaddress);
		i++;
	}
	fclose(fp);
	int n=i;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(strcmp(s[i].name,s[j].name) >0)
			{
				struct stud tmp;
				tmp=s[i];
				s[i]=s[j];
				s[j]=tmp;
			}
		}
	}
	fp=fopen("student.csv","w");
	for(int i=0;i<n;i++)
    {
        fprintf(fp,"%s, ", s[i].name);
        fprintf(fp,"%s, ", s[i].age);
        fprintf(fp,"%s, ", s[i].dob);
        fprintf(fp,"%s, ", s[i].aadhaar);
        fprintf(fp,"%s, ", s[i].stph);
        fprintf(fp,"%s, ", s[i].stmail);
        fprintf(fp,"%s, ", s[i].fathername);
        fprintf(fp,"%s, ", s[i].fatherphone);
        fprintf(fp,"%s, ", s[i].fathermail);
        fprintf(fp,"%s, ", s[i].mothername);
        fprintf(fp,"%s, ", s[i].motherphone);
        fprintf(fp,"%s, ", s[i].mothermail);
        fprintf(fp,"%s, ", s[i].stcurraddress);
        fprintf(fp,"%s\n", s[i].stperaddress);
    }
    fclose(fp);
}

void save(GtkButton* storebutton, GtkEntry* name_entry) {
    FILE *fp;
    struct stud a;
    fp=fopen("student.csv", "a+");
    strcpy(a.name,(char *)gtk_entry_get_text(GTK_ENTRY(name_entry)));
    fprintf(fp,"%s,", a.name);
    strcpy(a.age,(char *)gtk_entry_get_text(GTK_ENTRY(age_entry)));
    fprintf(fp,"%s,", a.age);
    strcpy(a.dob,(char *)gtk_entry_get_text(GTK_ENTRY(dob_entry)));
    fprintf(fp,"%s,", a.dob);
    strcpy(a.aadhaar,(char *)gtk_entry_get_text(GTK_ENTRY(aadhaar_entry)));
    fprintf(fp,"%s,", a.aadhaar);
    strcpy(a.stph,(char *)gtk_entry_get_text(GTK_ENTRY(phone_entry)));
    fprintf(fp,"%s,", a.stph);
    strcpy(a.stmail,(char *)gtk_entry_get_text(GTK_ENTRY(email_entry)));
    fprintf(fp,"%s,", a.stmail);
    strcpy(a.fathername,(char *)gtk_entry_get_text(GTK_ENTRY(father_name_entry)));
    fprintf(fp,"%s,", a.fathername);
    strcpy(a.fatherphone,(char *)gtk_entry_get_text(GTK_ENTRY(fphone_entry)));
    fprintf(fp,"%s,", a.fatherphone);
    strcpy(a.fathermail,(char *)gtk_entry_get_text(GTK_ENTRY(femail_entry)));
    fprintf(fp,"%s,", a.fathermail);
    strcpy(a.mothername,(char *)gtk_entry_get_text(GTK_ENTRY(mother_name_entry)));
    fprintf(fp,"%s,", a.mothername);
    strcpy(a.motherphone,(char *)gtk_entry_get_text(GTK_ENTRY(mphone_entry)));
    fprintf(fp,"%s,", a.motherphone);
    strcpy(a.mothermail,(char *)gtk_entry_get_text(GTK_ENTRY(memail_entry)));
    fprintf(fp,"%s,", a.mothermail);
    strcpy(a.stcurraddress,(char *)gtk_entry_get_text(GTK_ENTRY(caddress_entry)));
    fprintf(fp,"%s,", a.stcurraddress);
    strcpy(a.stperaddress,(char *)gtk_entry_get_text(GTK_ENTRY(paddress_entry)));
    fprintf(fp,"%s,\n", a.stperaddress);
    fclose(fp);
    gtk_entry_set_text(name_entry,"");
    gtk_entry_set_text(age_entry,"");
    gtk_entry_set_text(dob_entry,"");
    gtk_entry_set_text(aadhaar_entry,"");
    gtk_entry_set_text(phone_entry,"");
    gtk_entry_set_text(email_entry,"");
    gtk_entry_set_text(father_name_entry,"");
    gtk_entry_set_text(fphone_entry,"");
    gtk_entry_set_text(femail_entry,"");
    gtk_entry_set_text(mother_name_entry,"");
    gtk_entry_set_text(mphone_entry,"");
    gtk_entry_set_text(memail_entry,"");
    gtk_entry_set_text(caddress_entry,"");
    gtk_entry_set_text(paddress_entry,"");
    fclose(fp);
    sortname();
}

int main(int argc,char *argv[])
 {
     gtk_init(&argc,&argv);

     win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
     g_signal_connect(win,"delete_event",gtk_main_quit,NULL);
     gtk_window_set_default_size(win, 1500, 700);
     gtk_container_set_border_width(GTK_CONTAINER(win), 20);

     vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,10);
     sbox=gtk_box_new(GTK_ORIENTATION_VERTICAL,10);
     vbox1 = gtk_box_new(GTK_ORIENTATION_VERTICAL,10);
     ebox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,50);
     vbox2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 400);
     delbox=gtk_box_new(GTK_ORIENTATION_VERTICAL,10);
     gtk_box_pack_start(GTK_BOX(ebox), vbox,0,0,20);
     gtk_box_pack_start(GTK_BOX(ebox), vbox1,1,0,20);
     gtk_box_pack_start(GTK_BOX(vbox2), ebox,0,0,20);
     gtk_box_pack_start(GTK_BOX(vbox2), sbox,0,0,20);

     search_stud=gtk_label_new("ENTER NAME FOR STUDENT DETAILS");
     s_button=gtk_button_new_with_label("Search");
     gtk_box_pack_start(GTK_BOX(sbox),search_stud,0,0,0);
     tos_entry=gtk_entry_new();
     gtk_box_pack_start(GTK_BOX(sbox),tos_entry,0,0,0);
     gtk_box_pack_start(GTK_BOX(sbox),s_button,0,0,0);

     gtk_box_pack_start(GTK_BOX(sbox), delbox,0,0,20);
     del_btn=gtk_button_new_with_label("DELETE");
     del_label=gtk_label_new("ENTER NAME TO DELETE STUDENT DETAILS");
     gtk_box_pack_start(GTK_BOX(delbox), del_label,0,0,0);
     del_entry=gtk_entry_new();
     gtk_box_pack_start(GTK_BOX(delbox), del_entry,0,0,0);
     gtk_box_pack_start(GTK_BOX(delbox), del_btn, 0,0,0);

     new_stud=gtk_label_new("ENTER NEW STUDENT DETAILS");
     gtk_box_pack_start(GTK_BOX(vbox),new_stud,0,0,0);
     name_label=gtk_label_new("Enter your name:");
     gtk_box_pack_start(GTK_BOX(vbox),name_label,0,0,0);
    name_entry=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox),name_entry,0,0,0);
    age_label=gtk_label_new("Enter your age:");
   gtk_box_pack_start(GTK_BOX(vbox),age_label,0,0,0);
    age_entry=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox),age_entry,0,0,0);
    dob_label=gtk_label_new("Enter your date of birth DD/MM/YYYY:");
    gtk_box_pack_start(GTK_BOX(vbox),dob_label,0,0,0);
    dob_entry=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox),dob_entry,0,0,0);
    aadhaar_label=gtk_label_new("Enter your Aadhaar number:");
    gtk_box_pack_start(GTK_BOX(vbox),aadhaar_label,0,0,0);
    aadhaar_entry=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox),aadhaar_entry,0,0,0);
    phone_label=gtk_label_new("Enter student's phone number");
    gtk_box_pack_start(GTK_BOX(vbox),phone_label,0,0,0);
    phone_entry=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox),phone_entry,0,0,0);
    email_label=gtk_label_new("Enter student's email address:");
    gtk_box_pack_start(GTK_BOX(vbox),email_label,0,0,0);
    email_entry=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox),email_entry,0,0,0);
    father_name_label=gtk_label_new("Enter Father's Name:");
    gtk_box_pack_start(GTK_BOX(vbox),father_name_label,0,0,0);
    father_name_entry=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox),father_name_entry,0,0,0);
    fphone_label=gtk_label_new("Enter Father's phone number:");
    gtk_box_pack_start(GTK_BOX(vbox),fphone_label,0,0,0);
    fphone_entry=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox),fphone_entry,0,0,0);
    femail_label=gtk_label_new("Enter Father's email:");
    gtk_box_pack_start(GTK_BOX(vbox),femail_label,0,0,0);
    femail_entry=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox),femail_entry,0,0,0);
    mother_name_label=gtk_label_new("Enter Mother's Name:");
    gtk_box_pack_start(GTK_BOX(vbox1),mother_name_label,0,0,0);
    mother_name_entry=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox1),mother_name_entry,0,0,0);
    mphone_label=gtk_label_new("Enter Mother's phone number:");
    gtk_box_pack_start(GTK_BOX(vbox1),mphone_label,0,0,0);
    mphone_entry=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox1),mphone_entry,0,0,0);
    memail_label=gtk_label_new("Enter Mother's email address:");
    gtk_box_pack_start(GTK_BOX(vbox1),memail_label,0,0,0);
    memail_entry=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox1),memail_entry,0,0,0);
    caddress_label=gtk_label_new("Enter Student's current address:");
    gtk_box_pack_start(GTK_BOX(vbox1),caddress_label,0,0,0);
    caddress_entry=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox1),caddress_entry,0,0,0);
    paddress_label=gtk_label_new("Enter Student's Permanent Address:");
    gtk_box_pack_start(GTK_BOX(vbox1),paddress_label,0,0,0);
    paddress_entry=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox1),paddress_entry,0,0,0);
    storebutton=gtk_button_new_with_label("Save");
    gtk_box_pack_start(GTK_BOX(vbox1),storebutton,0,0,0);
    g_signal_connect(storebutton,"clicked",G_CALLBACK(save),name_entry);
    //g_signal_connect(s_button,"clicked",G_CALLBACK(search),tos_entry);
     gtk_container_add(GTK_CONTAINER(win), vbox2);

     gtk_widget_show_all(win);
     gtk_main();
     return 0;
 }
