void init()
{
    string msg;

    if( this_object() == this_player() ) return;

    // �Y this_player() �ݤ����o�ӤH���A�h���޵o�԰��C
    if( ! this_object()->visible(this_player()) ) return;

    // �ϰ�]�w
    if( environment()->is_area() && !area_environment(this_object(), this_player()) ) return;

    // �Y���西���ۤ������A�}�l�԰��C
    if( this_player()->is_killing(query("id")) ) {
        COMBAT_D->auto_fight(this_player(), this_object(), "hatred");
        return;
    }
    if( is_killing(this_player()->query("id")) )
    {
        COMBAT_D->auto_fight(this_object(), this_player(), "hatred");
        return;
    }
    // �J�����¾�~���N�D�ʧ���
    if( this_player()->query_class() == "work_sea" 
        || this_player()->query_class() == "soldier_sea" 
        || this_player()->query_class() == "officer_sea" 
        || this_player()->query_class() == "guard_sea" 
        || this_player()->query_class() == "general_sea"
        || this_player()->query_class() == "admiral_sea" ) {

        switch(random(4)) {
            case 0: msg = ""HIR"$N"HIR"�@����$n�ߨ�H���ۡG�u���x���ӰաI�v"NOR"\n\n"; break;
            case 1: msg = ""HIR"$N"HIR"���_�ԤM�ƾԡG�u�������I�v"NOR"\n\n"; break;
            case 2: msg = ""HIR"$N"HIR"�j�n�۵ۡG�u�e�観���x��ŧ�I�j�a�`�N�I�v"NOR"\n\n"; break;
            case 3: msg = ""HIR"$N"HIR"�j�q�G�u�O�������˪����x�����]�աI�v"NOR"\n\n"; break;
        }
        message_vision(msg, this_object(), this_player());
        this_object()->kill_ob(this_player());
        if( function_exists("accept_kill", this_player()) && !this_player()->is_killing(this_object()) && this_player()->accept_kill(this_object()) ) return;
        if( ! this_player()->is_killing(this_object()) ) this_player()->kill_ob(this_object());
    }
}
