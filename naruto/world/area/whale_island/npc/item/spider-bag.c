// bag.c

inherit ITEM;

void create()
{
          set_name("�j��G�U", ({ "spider stomach bag", "bag" }));
        set_weight(700);
        set_max_encumbrance(60000);
        if( !clonep() ) {
                set("unit", "��");
                set("value", 5000);
                set("long", "�@�����j���j��G�U�A�A�Q�n�˪F��i�h�]��C\n");
        }
        setup();
}

int accept_object() { return 1; }


