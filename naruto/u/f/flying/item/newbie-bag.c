// bag.c

inherit ITEM;

void create()
{
        set_name("火影新手包", ({ "newbie bag" ,"bag"}));
        set_weight(300);
        set_max_encumbrance(8000);
        if( !clonep() ) {
                set("unit", "隻");
                set("value", 10);
                set("long", "火影新手包，裡面有新手必需品。\n");
        }
        setup();
}

int accept_object() { return 1; }

