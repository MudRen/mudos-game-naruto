// bag.c

inherit ITEM;

void create()
{
        set_name("���v�s��]", ({ "newbie bag" ,"bag"}));
        set_weight(300);
        set_max_encumbrance(8000);
        if( !clonep() ) {
                set("unit", "��");
                set("value", 10);
                set("long", "���v�s��]�A�̭����s�⥲�ݫ~�C\n");
        }
        setup();
}

int accept_object() { return 1; }

