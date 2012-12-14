#include <stdlib.h>
#include <gtk/gtk.h>
#include <glib/gprintf.h>

enum {
TEXT_COLUMN,
TOGGLE_COLUMN,
N_COLUMN
};

void e_lister(void)
{
    GtkWidget *pListView;
    GtkWidget *pScrollbar;
    GtkListStore *pListStore;
    GtkTreeViewColumn *pColumn;
    GtkCellRenderer *pCellRenderer;
    gchar *sTexte;
    gint i;

    /* Creation du modele */
    pListStore = gtk_list_store_new(N_COLUMN, G_TYPE_STRING, G_TYPE_BOOLEAN);
    sTexte = g_malloc(12);


GtkTreeIter pIter;
g_sprintf(sTexte, "employe");
/* Creation de la nouvelle ligne */
gtk_list_store_append(pListStore, &pIter);
/* Mise a jour des donnees */
gtk_list_store_set(pListStore, &pIter,
TEXT_COLUMN, sTexte,
TOGGLE_COLUMN, TRUE,
1);
}
g_free(sTexte);
/* Creation de la vue */
pListView = gtk_tree_view_new_with_model(GTK_TREE_MODEL(pListStore));
/* Creation de la premiere colonne */
pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("Nom",
pCellRenderer,
"text", TEXT_COLUMN,
NULL);
/* Ajout de la colonne à la vue */
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);
/* Creation de la deuxieme colonne */
pCellRenderer = gtk_cell_renderer_toggle_new();
pColumn = gtk_tree_view_column_new_with_attributes("CheckBox",
pCellRenderer,
"active", TOGGLE_COLUMN,
NULL);
/* Ajout de la colonne à la vue */
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);
/* Ajout de la vue a la fenetre */
pScrollbar = gtk_scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(pScrollbar),
GTK_POLICY_AUTOMATIC,
GTK_POLICY_AUTOMATIC);
gtk_container_add(GTK_CONTAINER(pScrollbar), pListView);
gtk_container_add(GTK_CONTAINER(fenetre), pScrollbar);
}
