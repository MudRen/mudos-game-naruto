// bag.c

inherit ITEM;

void create()
{
    set_name("���l�m���c", ({ "box", "_WP_BOX_" }));
    set_weight(700);
    set_max_encumbrance(90000);
    if( !clonep() ) {
        set("unit", "��");
        set("value", 3000);
        set("no_get", 1);
        set("no_sac", 1);
        set("no_box", 1);
        set("long", "�ݰ_�Ӥ��O�ܤj���m���c�A�����Ǳa�i�H�N���~�e�J���l���C\n");
    }
    setup();
}

int accept_object() { return 1; }

