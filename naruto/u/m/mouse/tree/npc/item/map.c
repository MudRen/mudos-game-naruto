inherit ITEM;

void create()
{
    set_name("�j�Ѵ˪L�a��", ({ "old forest map", "map" }));
    set_weight(100);
    if( !clonep() ) {
        set("unit", "�i");
        set("value", 10);
        set("long","�@�i�j�Ѫ��a�ϡA�i�H��(look �j�Ѧa��)�[�ݡC");
    }
    setup();
}
void init()
{
    add_action("do_look", "look");
}
int do_look(string arg)
{
    if( !arg ) return 0;
    if( arg == "�j�Ѧa��" ) {
        string line;
        line  = "�@\n";
        line += "�@�i�����q��ӨӪ��a�ϡA�W�Y�e�F�@�ǩ_�_�ǩǪ��Ÿ�...\n";
        line += "�@\n";
        line += "��\n";
        line += "�x\n";
        line += "���w���w���w�J�w���w��\n";
        line += "    �x      �x      �x\n";
        line += "���w���w���w���w���w���w��\n";
        line += "�x        ��            �x\n";
        line += "���w���w���w���w���w���w���w��\n";
        line += "            �x          �x    \n";
        line += "    ���w���w��  ��  ���w���w���w��\n";
        line += "        �x          �x           \n";
        line += "        ���w���w���w���w���w��\n";
        line += "            �x              �x\n";
        line += "            ���w���w���w���w��\n";
        line += "�@\n";
        line += "�@\n";
        write(line);
        return 1;
    }
}
