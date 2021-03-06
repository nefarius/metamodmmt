// dllmain.cpp : Defines the entry point for the DLL application.
#include "header.h"

#include <mmsystem.h>
#include <stdlib.h>
#include <Shlwapi.h>

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "Shlwapi.lib")

EXTERN_C IMAGE_DOS_HEADER __ImageBase;

HANDLE hCancelEvt;

DWORD initMain()
{
    //
    // Set timer interval to lowest value (1ms)
    // 
    timeBeginPeriod(1);

    WaitForSingleObject(hCancelEvt, INFINITE);

    //
    // Restore original timer interval
    // 
    timeEndPeriod(1);

    return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    static HINSTANCE hL;
    WCHAR DllPath[MAX_PATH] = { 0 };
    WCHAR OrgDllPath[MAX_PATH] = { 0 };
    
    DisableThreadLibraryCalls(static_cast<HMODULE>(hModule));

    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    
        hCancelEvt = CreateEvent(nullptr, FALSE, FALSE, nullptr);
        
        GetModuleFileNameW(reinterpret_cast<HINSTANCE>(&__ImageBase), DllPath, _countof(DllPath));
        PathRemoveFileSpec(DllPath);
        PathCombine(OrgDllPath, DllPath, L"metamod_org.dll");

        hL = LoadLibrary(OrgDllPath);
        if (!hL) return false;

        CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(initMain), nullptr, 0, nullptr);

        break;
    
    case DLL_PROCESS_DETACH:

        SetEvent(hCancelEvt);
        CloseHandle(hCancelEvt);

        FreeLibrary(hL);
        break;
    }
    return TRUE;
}

#pragma region Exports

#pragma comment(linker, "/export:AngleIMatrix=metamod_org.AngleIMatrix")

#pragma comment(linker, "/export:AngleMatrix=metamod_org.AngleMatrix")

#pragma comment(linker, "/export:BALLS_airball=metamod_org.BALLS_airball")

#pragma comment(linker, "/export:CTF_Map=metamod_org.CTF_Map")

#pragma comment(linker, "/export:CreateInterface=metamod_org.CreateInterface")

#pragma comment(linker, "/export:DLLClassName=metamod_org.DLLClassName")

#pragma comment(linker, "/export:DelayedUse=metamod_org.DelayedUse")

#pragma comment(linker, "/export:Electro_Bolt=metamod_org.Electro_Bolt")

#pragma comment(linker, "/export:FISHINGROD_bolt=metamod_org.FISHINGROD_bolt")

#pragma comment(linker, "/export:FOOT_bolt=metamod_org.FOOT_bolt")

#pragma comment(linker, "/export:FlyingTomaHawk=metamod_org.FlyingTomaHawk")

#pragma comment(linker, "/export:GetChaseOrigin=metamod_org.GetChaseOrigin")

#pragma comment(linker, "/export:IsoBomb=metamod_org.IsoBomb")

#pragma comment(linker, "/export:PythRound=metamod_org.PythRound")

#pragma comment(linker, "/export:RONINTeamScore=metamod_org.RONINTeamScore")

#pragma comment(linker, "/export:SA_Model=metamod_org.SA_Model")

#pragma comment(linker, "/export:SCAVENGERTeamScore=metamod_org.SCAVENGERTeamScore")

#pragma comment(linker, "/export:Satelite__Laser=metamod_org.Satelite__Laser")

#pragma comment(linker, "/export:TSAmmoPack=metamod_org.TSAmmoPack")

#pragma comment(linker, "/export:TSWorldGun=metamod_org.TSWorldGun")

#pragma comment(linker, "/export:TS_PowerUp=metamod_org.TS_PowerUp")

#pragma comment(linker, "/export:TS_bomb=metamod_org.TS_bomb")

#pragma comment(linker, "/export:USMCTeamScore=metamod_org.USMCTeamScore")

#pragma comment(linker, "/export:Zombie2Spit=metamod_org.Zombie2Spit")

#pragma comment(linker, "/export:spit=metamod_org.spit")

#pragma comment(linker, "/export:squadfix=metamod_org.squadfix")

#pragma comment(linker, "/export:acidgib=metamod_org.acidgib")

#pragma comment(linker, "/export:active_bomb=metamod_org.active_bomb")

#pragma comment(linker, "/export:afterimage=metamod_org.afterimage")

#pragma comment(linker, "/export:aiscripted_sequence=metamod_org.aiscripted_sequence")

#pragma comment(linker, "/export:ak74grenade=metamod_org.ak74grenade")

#pragma comment(linker, "/export:alien_slave_energy_ball=metamod_org.alien_slave_energy_ball")

#pragma comment(linker, "/export:alien_slave_sapper=metamod_org.alien_slave_sapper")

#pragma comment(linker, "/export:alienresourcetower=metamod_org.alienresourcetower")

#pragma comment(linker, "/export:ambient_generic=metamod_org.ambient_generic")

#pragma comment(linker, "/export:ammo_0mm45=metamod_org.ammo_0mm45")

#pragma comment(linker, "/export:ammo_0mm50b=metamod_org.ammo_0mm50b")

#pragma comment(linker, "/export:ammo_10mmbuckshot=metamod_org.ammo_10mmbuckshot")

#pragma comment(linker, "/export:ammo_10mmbuckshotbox=metamod_org.ammo_10mmbuckshotbox")

#pragma comment(linker, "/export:ammo_127mm=metamod_org.ammo_127mm")

#pragma comment(linker, "/export:ammo_12g=metamod_org.ammo_12g")

#pragma comment(linker, "/export:ammo_1911clip=metamod_org.ammo_1911clip")

#pragma comment(linker, "/export:ammo_2mm=metamod_org.ammo_2mm")

#pragma comment(linker, "/export:ammo_30cal=metamod_org.ammo_30cal")

#pragma comment(linker, "/export:ammo_30mm=metamod_org.ammo_30mm")

#pragma comment(linker, "/export:ammo_338Magnum=metamod_org.ammo_338Magnum")

#pragma comment(linker, "/export:ammo_338magnum=metamod_org.ammo_338magnum")

#pragma comment(linker, "/export:ammo_357=metamod_org.ammo_357")

#pragma comment(linker, "/export:ammo_357SIG=metamod_org.ammo_357SIG")

#pragma comment(linker, "/export:ammo_357sig=metamod_org.ammo_357sig")

#pragma comment(linker, "/export:ammo_40glclip=metamod_org.ammo_40glclip")

#pragma comment(linker, "/export:ammo_40mm=metamod_org.ammo_40mm")

#pragma comment(linker, "/export:ammo_44=metamod_org.ammo_44")

#pragma comment(linker, "/export:ammo_45ACP=metamod_org.ammo_45ACP")

#pragma comment(linker, "/export:ammo_45acp=metamod_org.ammo_45acp")

#pragma comment(linker, "/export:ammo_45cal=metamod_org.ammo_45cal")

#pragma comment(linker, "/export:ammo_50AE=metamod_org.ammo_50AE")

#pragma comment(linker, "/export:ammo_50ae=metamod_org.ammo_50ae")

#pragma comment(linker, "/export:ammo_50cal=metamod_org.ammo_50cal")

#pragma comment(linker, "/export:ammo_556=metamod_org.ammo_556")

#pragma comment(linker, "/export:ammo_556AR=metamod_org.ammo_556AR")

#pragma comment(linker, "/export:ammo_556Nato=metamod_org.ammo_556Nato")

#pragma comment(linker, "/export:ammo_556box=metamod_org.ammo_556box")

#pragma comment(linker, "/export:ammo_556nato=metamod_org.ammo_556nato")

#pragma comment(linker, "/export:ammo_556natobox=metamod_org.ammo_556natobox")

#pragma comment(linker, "/export:ammo_57mm=metamod_org.ammo_57mm")

#pragma comment(linker, "/export:ammo_5mm56=metamod_org.ammo_5mm56")

#pragma comment(linker, "/export:ammo_5mm7=metamod_org.ammo_5mm7")

#pragma comment(linker, "/export:ammo_762=metamod_org.ammo_762")

#pragma comment(linker, "/export:ammo_762Magnum=metamod_org.ammo_762Magnum")

#pragma comment(linker, "/export:ammo_762Nato=metamod_org.ammo_762Nato")

#pragma comment(linker, "/export:ammo_762mmbox=metamod_org.ammo_762mmbox")

#pragma comment(linker, "/export:ammo_762nato=metamod_org.ammo_762nato")

#pragma comment(linker, "/export:ammo_762x54=metamod_org.ammo_762x54")

#pragma comment(linker, "/export:ammo_766mm=metamod_org.ammo_766mm")

#pragma comment(linker, "/export:ammo_7mm62=metamod_org.ammo_7mm62")

#pragma comment(linker, "/export:ammo_86mm=metamod_org.ammo_86mm")

#pragma comment(linker, "/export:ammo_8mm=metamod_org.ammo_8mm")

#pragma comment(linker, "/export:ammo_9mm=metamod_org.ammo_9mm")

#pragma comment(linker, "/export:ammo_9mmAR=metamod_org.ammo_9mmAR")

#pragma comment(linker, "/export:ammo_9mmbox=metamod_org.ammo_9mmbox")

#pragma comment(linker, "/export:ammo_9mmclip=metamod_org.ammo_9mmclip")

#pragma comment(linker, "/export:ammo_AK47clip=metamod_org.ammo_AK47clip")

#pragma comment(linker, "/export:ammo_ARgrenades=metamod_org.ammo_ARgrenades")

#pragma comment(linker, "/export:ammo_BALLS=metamod_org.ammo_BALLS")

#pragma comment(linker, "/export:ammo_CEnfield=metamod_org.ammo_CEnfield")

#pragma comment(linker, "/export:ammo_Deagle=metamod_org.ammo_Deagle")

#pragma comment(linker, "/export:ammo_Dmissile=metamod_org.ammo_Dmissile")

#pragma comment(linker, "/export:ammo_EnergyCells=metamod_org.ammo_EnergyCells")

#pragma comment(linker, "/export:ammo_FISHINGROD=metamod_org.ammo_FISHINGROD")

#pragma comment(linker, "/export:ammo_FOOT=metamod_org.ammo_FOOT")

#pragma comment(linker, "/export:ammo_FTclip=metamod_org.ammo_FTclip")

#pragma comment(linker, "/export:ammo_GMauserG98=metamod_org.ammo_GMauserG98")

#pragma comment(linker, "/export:ammo_GluonCells=metamod_org.ammo_GluonCells")

#pragma comment(linker, "/export:ammo_M16grenades=metamod_org.ammo_M16grenades")

#pragma comment(linker, "/export:ammo_MicroFusionCells=metamod_org.ammo_MicroFusionCells")

#pragma comment(linker, "/export:ammo_NGgrenades=metamod_org.ammo_NGgrenades")

#pragma comment(linker, "/export:ammo_ShockCore=metamod_org.ammo_ShockCore")

#pragma comment(linker, "/export:ammo_ShockGrenade=metamod_org.ammo_ShockGrenade")

#pragma comment(linker, "/export:ammo_SunOfGod=metamod_org.ammo_SunOfGod")

#pragma comment(linker, "/export:ammo_WTELEPORTERgrenades=metamod_org.ammo_WTELEPORTERgrenades")

#pragma comment(linker, "/export:ammo_adrenaline=metamod_org.ammo_adrenaline")

#pragma comment(linker, "/export:ammo_ak101=metamod_org.ammo_ak101")

#pragma comment(linker, "/export:ammo_ak105=metamod_org.ammo_ak105")

#pragma comment(linker, "/export:ammo_ak47=metamod_org.ammo_ak47")

#pragma comment(linker, "/export:ammo_ak47clip=metamod_org.ammo_ak47clip")

#pragma comment(linker, "/export:ammo_ak5=metamod_org.ammo_ak5")

#pragma comment(linker, "/export:ammo_ak74=metamod_org.ammo_ak74")

#pragma comment(linker, "/export:ammo_ak74clip=metamod_org.ammo_ak74clip")

#pragma comment(linker, "/export:ammo_ak74grenades=metamod_org.ammo_ak74grenades")

#pragma comment(linker, "/export:ammo_anaconda=metamod_org.ammo_anaconda")

#pragma comment(linker, "/export:ammo_ar10clip=metamod_org.ammo_ar10clip")

#pragma comment(linker, "/export:ammo_ar33clip=metamod_org.ammo_ar33clip")

#pragma comment(linker, "/export:ammo_areaammo=metamod_org.ammo_areaammo")

#pragma comment(linker, "/export:ammo_aug=metamod_org.ammo_aug")

#pragma comment(linker, "/export:ammo_awm=metamod_org.ammo_awm")

#pragma comment(linker, "/export:ammo_awp=metamod_org.ammo_awp")

#pragma comment(linker, "/export:ammo_axes=metamod_org.ammo_axes")

#pragma comment(linker, "/export:ammo_bar=metamod_org.ammo_bar")

#pragma comment(linker, "/export:ammo_baretta=metamod_org.ammo_baretta")

#pragma comment(linker, "/export:ammo_bazooka=metamod_org.ammo_bazooka")

#pragma comment(linker, "/export:ammo_beamgunclip=metamod_org.ammo_beamgunclip")

#pragma comment(linker, "/export:ammo_benelli=metamod_org.ammo_benelli")

#pragma comment(linker, "/export:ammo_ber92f=metamod_org.ammo_ber92f")

#pragma comment(linker, "/export:ammo_ber93r=metamod_org.ammo_ber93r")

#pragma comment(linker, "/export:ammo_beretta=metamod_org.ammo_beretta")

#pragma comment(linker, "/export:ammo_berettaclip=metamod_org.ammo_berettaclip")

#pragma comment(linker, "/export:ammo_berrett82clip=metamod_org.ammo_berrett82clip")

#pragma comment(linker, "/export:ammo_bfg=metamod_org.ammo_bfg")

#pragma comment(linker, "/export:ammo_bizon=metamod_org.ammo_bizon")

#pragma comment(linker, "/export:ammo_boltrifle=metamod_org.ammo_boltrifle")

#pragma comment(linker, "/export:ammo_bow=metamod_org.ammo_bow")

#pragma comment(linker, "/export:ammo_bren=metamod_org.ammo_bren")

#pragma comment(linker, "/export:ammo_brick=metamod_org.ammo_brick")

#pragma comment(linker, "/export:ammo_buckshot=metamod_org.ammo_buckshot")

#pragma comment(linker, "/export:ammo_buffalo=metamod_org.ammo_buffalo")

#pragma comment(linker, "/export:ammo_cannon=metamod_org.ammo_cannon")

#pragma comment(linker, "/export:ammo_caseless=metamod_org.ammo_caseless")

#pragma comment(linker, "/export:ammo_cell=metamod_org.ammo_cell")

#pragma comment(linker, "/export:ammo_cgrenade=metamod_org.ammo_cgrenade")

#pragma comment(linker, "/export:ammo_chemical=metamod_org.ammo_chemical")

#pragma comment(linker, "/export:ammo_cloaker=metamod_org.ammo_cloaker")

#pragma comment(linker, "/export:ammo_colt=metamod_org.ammo_colt")

#pragma comment(linker, "/export:ammo_colt45clip=metamod_org.ammo_colt45clip")

#pragma comment(linker, "/export:ammo_coltgov=metamod_org.ammo_coltgov")

#pragma comment(linker, "/export:ammo_colts=metamod_org.ammo_colts")

#pragma comment(linker, "/export:ammo_concussion=metamod_org.ammo_concussion")

#pragma comment(linker, "/export:ammo_cougarclip=metamod_org.ammo_cougarclip")

#pragma comment(linker, "/export:ammo_cpc=metamod_org.ammo_cpc")

#pragma comment(linker, "/export:ammo_crate=metamod_org.ammo_crate")

#pragma comment(linker, "/export:ammo_crossbow=metamod_org.ammo_crossbow")

#pragma comment(linker, "/export:ammo_d5kclip=metamod_org.ammo_d5kclip")

#pragma comment(linker, "/export:ammo_dbshot=metamod_org.ammo_dbshot")

#pragma comment(linker, "/export:ammo_dd44clip=metamod_org.ammo_dd44clip")

#pragma comment(linker, "/export:ammo_de50=metamod_org.ammo_de50")

#pragma comment(linker, "/export:ammo_deagle=metamod_org.ammo_deagle")

#pragma comment(linker, "/export:ammo_deagleclip=metamod_org.ammo_deagleclip")

#pragma comment(linker, "/export:ammo_deploygun=metamod_org.ammo_deploygun")

#pragma comment(linker, "/export:ammo_desert=metamod_org.ammo_desert")

#pragma comment(linker, "/export:ammo_dmlclip=metamod_org.ammo_dmlclip")

#pragma comment(linker, "/export:ammo_doubleshotgun=metamod_org.ammo_doubleshotgun")

#pragma comment(linker, "/export:ammo_dragunovclip=metamod_org.ammo_dragunovclip")

#pragma comment(linker, "/export:ammo_dsr1=metamod_org.ammo_dsr1")

#pragma comment(linker, "/export:ammo_dualberettas=metamod_org.ammo_dualberettas")

#pragma comment(linker, "/export:ammo_dualscorpion=metamod_org.ammo_dualscorpion")

#pragma comment(linker, "/export:ammo_dyno=metamod_org.ammo_dyno")

#pragma comment(linker, "/export:ammo_eagleclip=metamod_org.ammo_eagleclip")

#pragma comment(linker, "/export:ammo_egonclip=metamod_org.ammo_egonclip")

#pragma comment(linker, "/export:ammo_el_standard=metamod_org.ammo_el_standard")

#pragma comment(linker, "/export:ammo_enfield=metamod_org.ammo_enfield")

#pragma comment(linker, "/export:ammo_exploder=metamod_org.ammo_exploder")

#pragma comment(linker, "/export:ammo_explogun=metamod_org.ammo_explogun")

#pragma comment(linker, "/export:ammo_famas=metamod_org.ammo_famas")

#pragma comment(linker, "/export:ammo_famasclip=metamod_org.ammo_famasclip")

#pragma comment(linker, "/export:ammo_fg42=metamod_org.ammo_fg42")

#pragma comment(linker, "/export:ammo_fiveseven=metamod_org.ammo_fiveseven")

#pragma comment(linker, "/export:ammo_flameammo=metamod_org.ammo_flameammo")

#pragma comment(linker, "/export:ammo_flameclip=metamod_org.ammo_flameclip")

#pragma comment(linker, "/export:ammo_flashbang=metamod_org.ammo_flashbang")

#pragma comment(linker, "/export:ammo_fnfal=metamod_org.ammo_fnfal")

#pragma comment(linker, "/export:ammo_fnp90clip=metamod_org.ammo_fnp90clip")

#pragma comment(linker, "/export:ammo_frag=metamod_org.ammo_frag")

#pragma comment(linker, "/export:ammo_freezeclip=metamod_org.ammo_freezeclip")

#pragma comment(linker, "/export:ammo_fuel=metamod_org.ammo_fuel")

#pragma comment(linker, "/export:ammo_g11=metamod_org.ammo_g11")

#pragma comment(linker, "/export:ammo_g36=metamod_org.ammo_g36")

#pragma comment(linker, "/export:ammo_g36clip=metamod_org.ammo_g36clip")

#pragma comment(linker, "/export:ammo_g36e=metamod_org.ammo_g36e")

#pragma comment(linker, "/export:ammo_g36k=metamod_org.ammo_g36k")

#pragma comment(linker, "/export:ammo_g3a3=metamod_org.ammo_g3a3")

#pragma comment(linker, "/export:ammo_galil=metamod_org.ammo_galil")

#pragma comment(linker, "/export:ammo_garand=metamod_org.ammo_garand")

#pragma comment(linker, "/export:ammo_gatlinbox=metamod_org.ammo_gatlinbox")

#pragma comment(linker, "/export:ammo_gattlinggun=metamod_org.ammo_gattlinggun")

#pragma comment(linker, "/export:ammo_gaussclip=metamod_org.ammo_gaussclip")

#pragma comment(linker, "/export:ammo_generic_american=metamod_org.ammo_generic_american")

#pragma comment(linker, "/export:ammo_generic_british=metamod_org.ammo_generic_british")

#pragma comment(linker, "/export:ammo_generic_german=metamod_org.ammo_generic_german")

#pragma comment(linker, "/export:ammo_gewehr=metamod_org.ammo_gewehr")

#pragma comment(linker, "/export:ammo_glock17=metamod_org.ammo_glock17")

#pragma comment(linker, "/export:ammo_glock18=metamod_org.ammo_glock18")

#pragma comment(linker, "/export:ammo_glockclip=metamod_org.ammo_glockclip")

#pragma comment(linker, "/export:ammo_goldpp7clip=metamod_org.ammo_goldpp7clip")

#pragma comment(linker, "/export:ammo_gp25=metamod_org.ammo_gp25")

#pragma comment(linker, "/export:ammo_greasegun=metamod_org.ammo_greasegun")

#pragma comment(linker, "/export:ammo_grenades=metamod_org.ammo_grenades")

#pragma comment(linker, "/export:ammo_handcannon=metamod_org.ammo_handcannon")

#pragma comment(linker, "/export:ammo_helirockets=metamod_org.ammo_helirockets")

#pragma comment(linker, "/export:ammo_hellfire=metamod_org.ammo_hellfire")

#pragma comment(linker, "/export:ammo_hk21=metamod_org.ammo_hk21")

#pragma comment(linker, "/export:ammo_hk33clip=metamod_org.ammo_hk33clip")

#pragma comment(linker, "/export:ammo_hkmp5=metamod_org.ammo_hkmp5")

#pragma comment(linker, "/export:ammo_isotope=metamod_org.ammo_isotope")

#pragma comment(linker, "/export:ammo_jackhammer=metamod_org.ammo_jackhammer")

#pragma comment(linker, "/export:ammo_javelins=metamod_org.ammo_javelins")

#pragma comment(linker, "/export:ammo_k43=metamod_org.ammo_k43")

#pragma comment(linker, "/export:ammo_kar=metamod_org.ammo_kar")

#pragma comment(linker, "/export:ammo_kf7clip=metamod_org.ammo_kf7clip")

#pragma comment(linker, "/export:ammo_knife=metamod_org.ammo_knife")

#pragma comment(linker, "/export:ammo_knives=metamod_org.ammo_knives")

#pragma comment(linker, "/export:ammo_launcher=metamod_org.ammo_launcher")

#pragma comment(linker, "/export:ammo_lgclip=metamod_org.ammo_lgclip")

#pragma comment(linker, "/export:ammo_lgrenades=metamod_org.ammo_lgrenades")

#pragma comment(linker, "/export:ammo_lightning=metamod_org.ammo_lightning")

#pragma comment(linker, "/export:ammo_longbow=metamod_org.ammo_longbow")

#pragma comment(linker, "/export:ammo_longslide=metamod_org.ammo_longslide")

#pragma comment(linker, "/export:ammo_lrclip=metamod_org.ammo_lrclip")

#pragma comment(linker, "/export:ammo_luger=metamod_org.ammo_luger")

#pragma comment(linker, "/export:ammo_m11=metamod_org.ammo_m11")

#pragma comment(linker, "/export:ammo_m112=metamod_org.ammo_m112")

#pragma comment(linker, "/export:ammo_m134=metamod_org.ammo_m134")

#pragma comment(linker, "/export:ammo_m16=metamod_org.ammo_m16")

#pragma comment(linker, "/export:ammo_m16a2clip=metamod_org.ammo_m16a2clip")

#pragma comment(linker, "/export:ammo_m16clip=metamod_org.ammo_m16clip")

#pragma comment(linker, "/export:ammo_m1carbine=metamod_org.ammo_m1carbine")

#pragma comment(linker, "/export:ammo_m2=metamod_org.ammo_m2")

#pragma comment(linker, "/export:ammo_m203=metamod_org.ammo_m203")

#pragma comment(linker, "/export:ammo_m249=metamod_org.ammo_m249")

#pragma comment(linker, "/export:ammo_m4=metamod_org.ammo_m4")

#pragma comment(linker, "/export:ammo_m40a1clip=metamod_org.ammo_m40a1clip")

#pragma comment(linker, "/export:ammo_m4a1=metamod_org.ammo_m4a1")

#pragma comment(linker, "/export:ammo_m4clip=metamod_org.ammo_m4clip")

#pragma comment(linker, "/export:ammo_m60=metamod_org.ammo_m60")

#pragma comment(linker, "/export:ammo_m60clip=metamod_org.ammo_m60clip")

#pragma comment(linker, "/export:ammo_m79=metamod_org.ammo_m79")

#pragma comment(linker, "/export:ammo_m82=metamod_org.ammo_m82")

#pragma comment(linker, "/export:ammo_mac=metamod_org.ammo_mac")

#pragma comment(linker, "/export:ammo_mac10=metamod_org.ammo_mac10")

#pragma comment(linker, "/export:ammo_machinegun=metamod_org.ammo_machinegun")

#pragma comment(linker, "/export:ammo_markmusket=metamod_org.ammo_markmusket")

#pragma comment(linker, "/export:ammo_mc51=metamod_org.ammo_mc51")

#pragma comment(linker, "/export:ammo_mf2clip=metamod_org.ammo_mf2clip")

#pragma comment(linker, "/export:ammo_mg34=metamod_org.ammo_mg34")

#pragma comment(linker, "/export:ammo_mg36=metamod_org.ammo_mg36")

#pragma comment(linker, "/export:ammo_mg42=metamod_org.ammo_mg42")

#pragma comment(linker, "/export:ammo_mindrayclip=metamod_org.ammo_mindrayclip")

#pragma comment(linker, "/export:ammo_minigunClip=metamod_org.ammo_minigunClip")

#pragma comment(linker, "/export:ammo_minimissile=metamod_org.ammo_minimissile")

#pragma comment(linker, "/export:ammo_mk23=metamod_org.ammo_mk23")

#pragma comment(linker, "/export:ammo_mossberg=metamod_org.ammo_mossberg")

#pragma comment(linker, "/export:ammo_mp40=metamod_org.ammo_mp40")

#pragma comment(linker, "/export:ammo_mp44=metamod_org.ammo_mp44")

#pragma comment(linker, "/export:ammo_mp5=metamod_org.ammo_mp5")

#pragma comment(linker, "/export:ammo_mp5a2=metamod_org.ammo_mp5a2")

#pragma comment(linker, "/export:ammo_mp5a4=metamod_org.ammo_mp5a4")

#pragma comment(linker, "/export:ammo_mp5a5=metamod_org.ammo_mp5a5")

#pragma comment(linker, "/export:ammo_mp5clip=metamod_org.ammo_mp5clip")

#pragma comment(linker, "/export:ammo_mp5grenades=metamod_org.ammo_mp5grenades")

#pragma comment(linker, "/export:ammo_mp5k=metamod_org.ammo_mp5k")

#pragma comment(linker, "/export:ammo_mp5pdwclip=metamod_org.ammo_mp5pdwclip")

#pragma comment(linker, "/export:ammo_mp5sd=metamod_org.ammo_mp5sd")

#pragma comment(linker, "/export:ammo_msg90=metamod_org.ammo_msg90")

#pragma comment(linker, "/export:ammo_musketoon=metamod_org.ammo_musketoon")

#pragma comment(linker, "/export:ammo_nails=metamod_org.ammo_nails")

#pragma comment(linker, "/export:ammo_nato=metamod_org.ammo_nato")

#pragma comment(linker, "/export:ammo_nato308=metamod_org.ammo_nato308")

#pragma comment(linker, "/export:ammo_natoclip=metamod_org.ammo_natoclip")

#pragma comment(linker, "/export:ammo_needle=metamod_org.ammo_needle")

#pragma comment(linker, "/export:ammo_nuke=metamod_org.ammo_nuke")

#pragma comment(linker, "/export:ammo_null=metamod_org.ammo_null")

#pragma comment(linker, "/export:ammo_p99=metamod_org.ammo_p99")

#pragma comment(linker, "/export:ammo_p99clip=metamod_org.ammo_p99clip")

#pragma comment(linker, "/export:ammo_pdw=metamod_org.ammo_pdw")

#pragma comment(linker, "/export:ammo_phantomclip=metamod_org.ammo_phantomclip")

#pragma comment(linker, "/export:ammo_piat=metamod_org.ammo_piat")

#pragma comment(linker, "/export:ammo_pistol=metamod_org.ammo_pistol")

#pragma comment(linker, "/export:ammo_pistolet=metamod_org.ammo_pistolet")

#pragma comment(linker, "/export:ammo_pkm=metamod_org.ammo_pkm")

#pragma comment(linker, "/export:ammo_pkmclip=metamod_org.ammo_pkmclip")

#pragma comment(linker, "/export:ammo_powercell=metamod_org.ammo_powercell")

#pragma comment(linker, "/export:ammo_pschreck=metamod_org.ammo_pschreck")

#pragma comment(linker, "/export:ammo_psg1=metamod_org.ammo_psg1")

#pragma comment(linker, "/export:ammo_psg1clip=metamod_org.ammo_psg1clip")

#pragma comment(linker, "/export:ammo_quad=metamod_org.ammo_quad")

#pragma comment(linker, "/export:ammo_railgun=metamod_org.ammo_railgun")

#pragma comment(linker, "/export:ammo_rcp90clip=metamod_org.ammo_rcp90clip")

#pragma comment(linker, "/export:ammo_remington=metamod_org.ammo_remington")

#pragma comment(linker, "/export:ammo_rifleclip=metamod_org.ammo_rifleclip")

#pragma comment(linker, "/export:ammo_rifleshot=metamod_org.ammo_rifleshot")

#pragma comment(linker, "/export:ammo_rocket=metamod_org.ammo_rocket")

#pragma comment(linker, "/export:ammo_rocketlauncher=metamod_org.ammo_rocketlauncher")

#pragma comment(linker, "/export:ammo_rocketpistol=metamod_org.ammo_rocketpistol")

#pragma comment(linker, "/export:ammo_rockets=metamod_org.ammo_rockets")

#pragma comment(linker, "/export:ammo_rpgclip=metamod_org.ammo_rpgclip")

#pragma comment(linker, "/export:ammo_rs202m2=metamod_org.ammo_rs202m2")

#pragma comment(linker, "/export:ammo_rs_grenade=metamod_org.ammo_rs_grenade")

#pragma comment(linker, "/export:ammo_rs_psi=metamod_org.ammo_rs_psi")

#pragma comment(linker, "/export:ammo_ruger=metamod_org.ammo_ruger")

#pragma comment(linker, "/export:ammo_sa80clip=metamod_org.ammo_sa80clip")

#pragma comment(linker, "/export:ammo_saa=metamod_org.ammo_saa")

#pragma comment(linker, "/export:ammo_saiga=metamod_org.ammo_saiga")

#pragma comment(linker, "/export:ammo_sako=metamod_org.ammo_sako")

#pragma comment(linker, "/export:ammo_satchels=metamod_org.ammo_satchels")

#pragma comment(linker, "/export:ammo_sbarrelshot=metamod_org.ammo_sbarrelshot")

#pragma comment(linker, "/export:ammo_scatterclip=metamod_org.ammo_scatterclip")

#pragma comment(linker, "/export:ammo_scopedkar=metamod_org.ammo_scopedkar")

#pragma comment(linker, "/export:ammo_shells=metamod_org.ammo_shells")

#pragma comment(linker, "/export:ammo_shot=metamod_org.ammo_shot")

#pragma comment(linker, "/export:ammo_shrapnel=metamod_org.ammo_shrapnel")

#pragma comment(linker, "/export:ammo_sig245clip=metamod_org.ammo_sig245clip")

#pragma comment(linker, "/export:ammo_silverpp7clip=metamod_org.ammo_silverpp7clip")

#pragma comment(linker, "/export:ammo_sks=metamod_org.ammo_sks")

#pragma comment(linker, "/export:ammo_slugs=metamod_org.ammo_slugs")

#pragma comment(linker, "/export:ammo_smg9=metamod_org.ammo_smg9")

#pragma comment(linker, "/export:ammo_snUZI=metamod_org.ammo_snUZI")

#pragma comment(linker, "/export:ammo_sniper=metamod_org.ammo_sniper")

#pragma comment(linker, "/export:ammo_spas12=metamod_org.ammo_spas12")

#pragma comment(linker, "/export:ammo_spasclip=metamod_org.ammo_spasclip")

#pragma comment(linker, "/export:ammo_spellbook=metamod_org.ammo_spellbook")

#pragma comment(linker, "/export:ammo_spitcarb=metamod_org.ammo_spitcarb")

#pragma comment(linker, "/export:ammo_spitclip=metamod_org.ammo_spitclip")

#pragma comment(linker, "/export:ammo_spore=metamod_org.ammo_spore")

#pragma comment(linker, "/export:ammo_spring=metamod_org.ammo_spring")

#pragma comment(linker, "/export:ammo_srifleclip=metamod_org.ammo_srifleclip")

#pragma comment(linker, "/export:ammo_ssg3000=metamod_org.ammo_ssg3000")

#pragma comment(linker, "/export:ammo_st_far=metamod_org.ammo_st_far")

#pragma comment(linker, "/export:ammo_st_heavy=metamod_org.ammo_st_heavy")

#pragma comment(linker, "/export:ammo_st_medium=metamod_org.ammo_st_medium")

#pragma comment(linker, "/export:ammo_st_short=metamod_org.ammo_st_short")

#pragma comment(linker, "/export:ammo_st_special1=metamod_org.ammo_st_special1")

#pragma comment(linker, "/export:ammo_st_special2=metamod_org.ammo_st_special2")

#pragma comment(linker, "/export:ammo_sten=metamod_org.ammo_sten")

#pragma comment(linker, "/export:ammo_sterling=metamod_org.ammo_sterling")

#pragma comment(linker, "/export:ammo_steyr_m40=metamod_org.ammo_steyr_m40")

#pragma comment(linker, "/export:ammo_stg24=metamod_org.ammo_stg24")

#pragma comment(linker, "/export:ammo_stoner=metamod_org.ammo_stoner")

#pragma comment(linker, "/export:ammo_stonerscope=metamod_org.ammo_stonerscope")

#pragma comment(linker, "/export:ammo_stonersilencer=metamod_org.ammo_stonersilencer")

#pragma comment(linker, "/export:ammo_stormcell=metamod_org.ammo_stormcell")

#pragma comment(linker, "/export:ammo_stubcoolant=metamod_org.ammo_stubcoolant")

#pragma comment(linker, "/export:ammo_stumpbox=metamod_org.ammo_stumpbox")

#pragma comment(linker, "/export:ammo_svd=metamod_org.ammo_svd")

#pragma comment(linker, "/export:ammo_swarm_xen_secondary=metamod_org.ammo_swarm_xen_secondary")

#pragma comment(linker, "/export:ammo_swarmprimary=metamod_org.ammo_swarmprimary")

#pragma comment(linker, "/export:ammo_swarmsecondary=metamod_org.ammo_swarmsecondary")

#pragma comment(linker, "/export:ammo_synthol=metamod_org.ammo_synthol")

#pragma comment(linker, "/export:ammo_tec9=metamod_org.ammo_tec9")

#pragma comment(linker, "/export:ammo_thompson=metamod_org.ammo_thompson")

#pragma comment(linker, "/export:ammo_tommy=metamod_org.ammo_tommy")

#pragma comment(linker, "/export:ammo_tommygun=metamod_org.ammo_tommygun")

#pragma comment(linker, "/export:ammo_trigun=metamod_org.ammo_trigun")

#pragma comment(linker, "/export:ammo_ump45=metamod_org.ammo_ump45")

#pragma comment(linker, "/export:ammo_uranium235=metamod_org.ammo_uranium235")

#pragma comment(linker, "/export:ammo_uranium238=metamod_org.ammo_uranium238")

#pragma comment(linker, "/export:ammo_usp=metamod_org.ammo_usp")

#pragma comment(linker, "/export:ammo_uspclip=metamod_org.ammo_uspclip")

#pragma comment(linker, "/export:ammo_uzi=metamod_org.ammo_uzi")

#pragma comment(linker, "/export:ammo_uziclip=metamod_org.ammo_uziclip")

#pragma comment(linker, "/export:ammo_veprclip=metamod_org.ammo_veprclip")

#pragma comment(linker, "/export:ammo_vomitclip=metamod_org.ammo_vomitclip")

#pragma comment(linker, "/export:ammo_vulcan=metamod_org.ammo_vulcan")

#pragma comment(linker, "/export:ammo_wa2000=metamod_org.ammo_wa2000")

#pragma comment(linker, "/export:ammo_webley=metamod_org.ammo_webley")

#pragma comment(linker, "/export:ammo_whiskey=metamod_org.ammo_whiskey")

#pragma comment(linker, "/export:ammo_winchester=metamod_org.ammo_winchester")

#pragma comment(linker, "/export:ammo_winchesterclip=metamod_org.ammo_winchesterclip")

#pragma comment(linker, "/export:ammo_xbolts=metamod_org.ammo_xbolts")

#pragma comment(linker, "/export:ammo_xm4=metamod_org.ammo_xm4")

#pragma comment(linker, "/export:ammo_xm4slug=metamod_org.ammo_xm4slug")

#pragma comment(linker, "/export:ammo_zmgclip=metamod_org.ammo_zmgclip")

#pragma comment(linker, "/export:ammobox=metamod_org.ammobox")

#pragma comment(linker, "/export:antifric_timer=metamod_org.antifric_timer")

#pragma comment(linker, "/export:antifriction_grenade=metamod_org.antifriction_grenade")

#pragma comment(linker, "/export:arcade_points=metamod_org.arcade_points")

#pragma comment(linker, "/export:armoury_entity=metamod_org.armoury_entity")

#pragma comment(linker, "/export:arms_dealer=metamod_org.arms_dealer")

#pragma comment(linker, "/export:arrow=metamod_org.arrow")

#pragma comment(linker, "/export:asl_charge_flare=metamod_org.asl_charge_flare")

#pragma comment(linker, "/export:aura=metamod_org.aura")

#pragma comment(linker, "/export:authenticationmanager=metamod_org.authenticationmanager")

#pragma comment(linker, "/export:autogl_gren=metamod_org.autogl_gren")

#pragma comment(linker, "/export:ball_launcher=metamod_org.ball_launcher")

#pragma comment(linker, "/export:ball_lightning=metamod_org.ball_lightning")

#pragma comment(linker, "/export:balle=metamod_org.balle")

#pragma comment(linker, "/export:banana=metamod_org.banana")

#pragma comment(linker, "/export:bankinterest=metamod_org.bankinterest")

#pragma comment(linker, "/export:barneymine=metamod_org.barneymine")

#pragma comment(linker, "/export:base_drive_ent=metamod_org.base_drive_ent")

#pragma comment(linker, "/export:basecurse=metamod_org.basecurse")

#pragma comment(linker, "/export:bb_ammo=metamod_org.bb_ammo")

#pragma comment(linker, "/export:bb_custommission=metamod_org.bb_custommission")

#pragma comment(linker, "/export:bb_equipment=metamod_org.bb_equipment")

#pragma comment(linker, "/export:bb_escape_final=metamod_org.bb_escape_final")

#pragma comment(linker, "/export:bb_escape_radar=metamod_org.bb_escape_radar")

#pragma comment(linker, "/export:bb_escapeair=metamod_org.bb_escapeair")

#pragma comment(linker, "/export:bb_funk=metamod_org.bb_funk")

#pragma comment(linker, "/export:bb_healthkit=metamod_org.bb_healthkit")

#pragma comment(linker, "/export:bb_mapmission=metamod_org.bb_mapmission")

#pragma comment(linker, "/export:bb_mission_zone=metamod_org.bb_mission_zone")

#pragma comment(linker, "/export:bb_objective_item=metamod_org.bb_objective_item")

#pragma comment(linker, "/export:bb_objectives=metamod_org.bb_objectives")

#pragma comment(linker, "/export:bb_spawn_player=metamod_org.bb_spawn_player")

#pragma comment(linker, "/export:bb_spawn_zombie=metamod_org.bb_spawn_zombie")

#pragma comment(linker, "/export:bb_tank=metamod_org.bb_tank")

#pragma comment(linker, "/export:bb_waypoint=metamod_org.bb_waypoint")

#pragma comment(linker, "/export:bb_zombie_player=metamod_org.bb_zombie_player")

#pragma comment(linker, "/export:bbody=metamod_org.bbody")

#pragma comment(linker, "/export:beam=metamod_org.beam")

#pragma comment(linker, "/export:beam_attack=metamod_org.beam_attack")

#pragma comment(linker, "/export:beamshot=metamod_org.beamshot")

#pragma comment(linker, "/export:bean=metamod_org.bean")

#pragma comment(linker, "/export:beanstalk=metamod_org.beanstalk")

#pragma comment(linker, "/export:bfg10k=metamod_org.bfg10k")

#pragma comment(linker, "/export:big_bang=metamod_org.big_bang")

#pragma comment(linker, "/export:big_disk=metamod_org.big_disk")

#pragma comment(linker, "/export:big_lance_proj=metamod_org.big_lance_proj")

#pragma comment(linker, "/export:bird=metamod_org.bird")

#pragma comment(linker, "/export:black_hole=metamod_org.black_hole")

#pragma comment(linker, "/export:blade=metamod_org.blade")

#pragma comment(linker, "/export:blaster_beam=metamod_org.blaster_beam")

#pragma comment(linker, "/export:blaster_bolt=metamod_org.blaster_bolt")

#pragma comment(linker, "/export:bmortar=metamod_org.bmortar")

#pragma comment(linker, "/export:bodyque=metamod_org.bodyque")

#pragma comment(linker, "/export:bone_follow=metamod_org.bone_follow")

#pragma comment(linker, "/export:boolean_multisource=metamod_org.boolean_multisource")

#pragma comment(linker, "/export:booty_it=metamod_org.booty_it")

#pragma comment(linker, "/export:bot=metamod_org.bot")

#pragma comment(linker, "/export:bot_waypoint=metamod_org.bot_waypoint")

#pragma comment(linker, "/export:bouncy_bolt=metamod_org.bouncy_bolt")

#pragma comment(linker, "/export:bouncy_tripmine=metamod_org.bouncy_tripmine")

#pragma comment(linker, "/export:bowie_bolt=metamod_org.bowie_bolt")

#pragma comment(linker, "/export:bubgren=metamod_org.bubgren")

#pragma comment(linker, "/export:building_dispenser=metamod_org.building_dispenser")

#pragma comment(linker, "/export:building_sentrygun=metamod_org.building_sentrygun")

#pragma comment(linker, "/export:building_sentrygun_base=metamod_org.building_sentrygun_base")

#pragma comment(linker, "/export:building_teleporter=metamod_org.building_teleporter")

#pragma comment(linker, "/export:bullet=metamod_org.bullet")

#pragma comment(linker, "/export:bumper_car_start=metamod_org.bumper_car_start")

#pragma comment(linker, "/export:burning_attack=metamod_org.burning_attack")

#pragma comment(linker, "/export:button_aiwallplug=metamod_org.button_aiwallplug")

#pragma comment(linker, "/export:button_target=metamod_org.button_target")

#pragma comment(linker, "/export:calc_position=metamod_org.calc_position")

#pragma comment(linker, "/export:calc_ratio=metamod_org.calc_ratio")

#pragma comment(linker, "/export:calc_subvelocity=metamod_org.calc_subvelocity")

#pragma comment(linker, "/export:calc_velocity_path=metamod_org.calc_velocity_path")

#pragma comment(linker, "/export:calc_velocity_polar=metamod_org.calc_velocity_polar")

#pragma comment(linker, "/export:candy=metamod_org.candy")

#pragma comment(linker, "/export:cannon_ball=metamod_org.cannon_ball")

#pragma comment(linker, "/export:capture_point=metamod_org.capture_point")

#pragma comment(linker, "/export:carried_book_team1=metamod_org.carried_book_team1")

#pragma comment(linker, "/export:carried_book_team2=metamod_org.carried_book_team2")

#pragma comment(linker, "/export:carried_flag_team1=metamod_org.carried_flag_team1")

#pragma comment(linker, "/export:carried_flag_team2=metamod_org.carried_flag_team2")

#pragma comment(linker, "/export:carry_resource=metamod_org.carry_resource")

#pragma comment(linker, "/export:carry_scientist=metamod_org.carry_scientist")

#pragma comment(linker, "/export:ce_psi_01=metamod_org.ce_psi_01")

#pragma comment(linker, "/export:ce_rocket_01=metamod_org.ce_rocket_01")

#pragma comment(linker, "/export:cflag=metamod_org.cflag")

#pragma comment(linker, "/export:chain_hurter=metamod_org.chain_hurter")

#pragma comment(linker, "/export:charge=metamod_org.charge")

#pragma comment(linker, "/export:charged_bolt=metamod_org.charged_bolt")

#pragma comment(linker, "/export:chronoclip=metamod_org.chronoclip")

#pragma comment(linker, "/export:cine_blood=metamod_org.cine_blood")

#pragma comment(linker, "/export:clbaby=metamod_org.clbaby")

#pragma comment(linker, "/export:clmomma=metamod_org.clmomma")

#pragma comment(linker, "/export:cm_rocket_01=metamod_org.cm_rocket_01")

#pragma comment(linker, "/export:cocklebur=metamod_org.cocklebur")

#pragma comment(linker, "/export:conc_charge=metamod_org.conc_charge")

#pragma comment(linker, "/export:control_forklift=metamod_org.control_forklift")

#pragma comment(linker, "/export:controller_charge_ball=metamod_org.controller_charge_ball")

#pragma comment(linker, "/export:controller_charged_ball=metamod_org.controller_charged_ball")

#pragma comment(linker, "/export:controller_energy_ball=metamod_org.controller_energy_ball")

#pragma comment(linker, "/export:controller_head_ball=metamod_org.controller_head_ball")

#pragma comment(linker, "/export:controller_health_ball=metamod_org.controller_health_ball")

#pragma comment(linker, "/export:controller_throw_ball=metamod_org.controller_throw_ball")

#pragma comment(linker, "/export:counter=metamod_org.counter")

#pragma comment(linker, "/export:crossbow_bolt=metamod_org.crossbow_bolt")

#pragma comment(linker, "/export:crowbar_rocket=metamod_org.crowbar_rocket")

#pragma comment(linker, "/export:crowbarang=metamod_org.crowbarang")

#pragma comment(linker, "/export:crowd=metamod_org.crowd")

#pragma comment(linker, "/export:ctb_point_one=metamod_org.ctb_point_one")

#pragma comment(linker, "/export:ctb_point_two=metamod_org.ctb_point_two")

#pragma comment(linker, "/export:ctc_capturepoint=metamod_org.ctc_capturepoint")

#pragma comment(linker, "/export:ctc_chicken=metamod_org.ctc_chicken")

#pragma comment(linker, "/export:ctf_blueflag=metamod_org.ctf_blueflag")

#pragma comment(linker, "/export:ctf_bluespawn=metamod_org.ctf_bluespawn")

#pragma comment(linker, "/export:ctf_cloak=metamod_org.ctf_cloak")

#pragma comment(linker, "/export:ctf_crowbar=metamod_org.ctf_crowbar")

#pragma comment(linker, "/export:ctf_cycle=metamod_org.ctf_cycle")

#pragma comment(linker, "/export:ctf_flag=metamod_org.ctf_flag")

#pragma comment(linker, "/export:ctf_flag_follow_blue=metamod_org.ctf_flag_follow_blue")

#pragma comment(linker, "/export:ctf_flag_follow_red=metamod_org.ctf_flag_follow_red")

#pragma comment(linker, "/export:ctf_flagzone=metamod_org.ctf_flagzone")

#pragma comment(linker, "/export:ctf_frag=metamod_org.ctf_frag")

#pragma comment(linker, "/export:ctf_hook=metamod_org.ctf_hook")

#pragma comment(linker, "/export:ctf_lowgrav=metamod_org.ctf_lowgrav")

#pragma comment(linker, "/export:ctf_protect=metamod_org.ctf_protect")

#pragma comment(linker, "/export:ctf_redflag=metamod_org.ctf_redflag")

#pragma comment(linker, "/export:ctf_redspawn=metamod_org.ctf_redspawn")

#pragma comment(linker, "/export:ctf_regen=metamod_org.ctf_regen")

#pragma comment(linker, "/export:ctf_rune=metamod_org.ctf_rune")

#pragma comment(linker, "/export:ctf_superglock=metamod_org.ctf_superglock")

#pragma comment(linker, "/export:ctf_trap=metamod_org.ctf_trap")

#pragma comment(linker, "/export:ctf_vamp=metamod_org.ctf_vamp")

#pragma comment(linker, "/export:curse_spawner=metamod_org.curse_spawner")

#pragma comment(linker, "/export:cust_11=metamod_org.cust_11")

#pragma comment(linker, "/export:cust_12=metamod_org.cust_12")

#pragma comment(linker, "/export:cust_13=metamod_org.cust_13")

#pragma comment(linker, "/export:cust_21=metamod_org.cust_21")

#pragma comment(linker, "/export:cust_22=metamod_org.cust_22")

#pragma comment(linker, "/export:cust_24=metamod_org.cust_24")

#pragma comment(linker, "/export:cust_25=metamod_org.cust_25")

#pragma comment(linker, "/export:cust_2GaussPistolSniper=metamod_org.cust_2GaussPistolSniper")

#pragma comment(linker, "/export:cust_2MinigunCooled=metamod_org.cust_2MinigunCooled")

#pragma comment(linker, "/export:cust_31=metamod_org.cust_31")

#pragma comment(linker, "/export:cust_33=metamod_org.cust_33")

#pragma comment(linker, "/export:cust_34=metamod_org.cust_34")

#pragma comment(linker, "/export:cust_41=metamod_org.cust_41")

#pragma comment(linker, "/export:cust_43=metamod_org.cust_43")

#pragma comment(linker, "/export:custom_precache=metamod_org.custom_precache")

#pragma comment(linker, "/export:cycler=metamod_org.cycler")

#pragma comment(linker, "/export:cycler_prdroid=metamod_org.cycler_prdroid")

#pragma comment(linker, "/export:cycler_sprite=metamod_org.cycler_sprite")

#pragma comment(linker, "/export:cycler_weapon=metamod_org.cycler_weapon")

#pragma comment(linker, "/export:cycler_wreckage=metamod_org.cycler_wreckage")

#pragma comment(linker, "/export:davespit=metamod_org.davespit")

#pragma comment(linker, "/export:db_spawner=metamod_org.db_spawner")

#pragma comment(linker, "/export:dc_info_objective=metamod_org.dc_info_objective")

#pragma comment(linker, "/export:dc_info_objectposition=metamod_org.dc_info_objectposition")

#pragma comment(linker, "/export:dc_object=metamod_org.dc_object")

#pragma comment(linker, "/export:dc_trigger_objectcapture=metamod_org.dc_trigger_objectcapture")

#pragma comment(linker, "/export:dc_trigger_reset=metamod_org.dc_trigger_reset")

#pragma comment(linker, "/export:dc_trigger_team=metamod_org.dc_trigger_team")

#pragma comment(linker, "/export:deadcorpse=metamod_org.deadcorpse")

#pragma comment(linker, "/export:deal_columbian_start=metamod_org.deal_columbian_start")

#pragma comment(linker, "/export:deal_italian_start=metamod_org.deal_italian_start")

#pragma comment(linker, "/export:deal_swat_start=metamod_org.deal_swat_start")

#pragma comment(linker, "/export:dealer=metamod_org.dealer")

#pragma comment(linker, "/export:death_ball=metamod_org.death_ball")

#pragma comment(linker, "/export:deathball=metamod_org.deathball")

#pragma comment(linker, "/export:deathsoul=metamod_org.deathsoul")

#pragma comment(linker, "/export:debris=metamod_org.debris")

#pragma comment(linker, "/export:decore_aicore=metamod_org.decore_aicore")

#pragma comment(linker, "/export:decore_asteroid=metamod_org.decore_asteroid")

#pragma comment(linker, "/export:decore_baboon=metamod_org.decore_baboon")

#pragma comment(linker, "/export:decore_bodygib=metamod_org.decore_bodygib")

#pragma comment(linker, "/export:decore_butterflyflock=metamod_org.decore_butterflyflock")

#pragma comment(linker, "/export:decore_cactus=metamod_org.decore_cactus")

#pragma comment(linker, "/export:decore_cam=metamod_org.decore_cam")

#pragma comment(linker, "/export:decore_corpse=metamod_org.decore_corpse")

#pragma comment(linker, "/export:decore_eagle=metamod_org.decore_eagle")

#pragma comment(linker, "/export:decore_explodable=metamod_org.decore_explodable")

#pragma comment(linker, "/export:decore_foot=metamod_org.decore_foot")

#pragma comment(linker, "/export:decore_goldskull=metamod_org.decore_goldskull")

#pragma comment(linker, "/export:decore_gutspile=metamod_org.decore_gutspile")

#pragma comment(linker, "/export:decore_hatgib=metamod_org.decore_hatgib")

#pragma comment(linker, "/export:decore_ice=metamod_org.decore_ice")

#pragma comment(linker, "/export:decore_mushroom=metamod_org.decore_mushroom")

#pragma comment(linker, "/export:decore_mushroom2=metamod_org.decore_mushroom2")

#pragma comment(linker, "/export:decore_nest=metamod_org.decore_nest")

#pragma comment(linker, "/export:decore_pipes=metamod_org.decore_pipes")

#pragma comment(linker, "/export:decore_prickle=metamod_org.decore_prickle")

#pragma comment(linker, "/export:decore_pteradon=metamod_org.decore_pteradon")

#pragma comment(linker, "/export:decore_scripted_boulder=metamod_org.decore_scripted_boulder")

#pragma comment(linker, "/export:decore_sittingtubemortar=metamod_org.decore_sittingtubemortar")

#pragma comment(linker, "/export:decore_spacebebris=metamod_org.decore_spacebebris")

#pragma comment(linker, "/export:decore_swampplants=metamod_org.decore_swampplants")

#pragma comment(linker, "/export:decore_torch=metamod_org.decore_torch")

#pragma comment(linker, "/export:decore_torchflame=metamod_org.decore_torchflame")

#pragma comment(linker, "/export:defensechamber=metamod_org.defensechamber")

#pragma comment(linker, "/export:demoman_mine=metamod_org.demoman_mine")

#pragma comment(linker, "/export:detpack=metamod_org.detpack")

#pragma comment(linker, "/export:dg_streak_spiral=metamod_org.dg_streak_spiral")

#pragma comment(linker, "/export:disc=metamod_org.disc")

#pragma comment(linker, "/export:disc_arena=metamod_org.disc_arena")

#pragma comment(linker, "/export:discarena=metamod_org.discarena")

#pragma comment(linker, "/export:dispball=metamod_org.dispball")

#pragma comment(linker, "/export:displacer_ball=metamod_org.displacer_ball")

#pragma comment(linker, "/export:dmgmirrorcurse=metamod_org.dmgmirrorcurse")

#pragma comment(linker, "/export:dmgscalecurse=metamod_org.dmgscalecurse")

#pragma comment(linker, "/export:dod_ammo=metamod_org.dod_ammo")

#pragma comment(linker, "/export:dod_ammo_depot=metamod_org.dod_ammo_depot")

#pragma comment(linker, "/export:dod_camera=metamod_org.dod_camera")

#pragma comment(linker, "/export:dod_capture_area=metamod_org.dod_capture_area")

#pragma comment(linker, "/export:dod_control_point=metamod_org.dod_control_point")

#pragma comment(linker, "/export:dod_control_point_master=metamod_org.dod_control_point_master")

#pragma comment(linker, "/export:dod_location=metamod_org.dod_location")

#pragma comment(linker, "/export:dod_mapmarker=metamod_org.dod_mapmarker")

#pragma comment(linker, "/export:dod_object=metamod_org.dod_object")

#pragma comment(linker, "/export:dod_object_goal=metamod_org.dod_object_goal")

#pragma comment(linker, "/export:dod_point_relay=metamod_org.dod_point_relay")

#pragma comment(linker, "/export:dod_preround=metamod_org.dod_preround")

#pragma comment(linker, "/export:dod_round_timer=metamod_org.dod_round_timer")

#pragma comment(linker, "/export:dod_score_ent=metamod_org.dod_score_ent")

#pragma comment(linker, "/export:dod_secondary=metamod_org.dod_secondary")

#pragma comment(linker, "/export:dod_stats=metamod_org.dod_stats")

#pragma comment(linker, "/export:dod_trigger_sandbag=metamod_org.dod_trigger_sandbag")

#pragma comment(linker, "/export:dove_flock=metamod_org.dove_flock")

#pragma comment(linker, "/export:dove_flyer=metamod_org.dove_flyer")

#pragma comment(linker, "/export:dragonball=metamod_org.dragonball")

#pragma comment(linker, "/export:drive_agrunt=metamod_org.drive_agrunt")

#pragma comment(linker, "/export:drive_agrunt_spawner=metamod_org.drive_agrunt_spawner")

#pragma comment(linker, "/export:drive_apache=metamod_org.drive_apache")

#pragma comment(linker, "/export:drive_apache_spawner=metamod_org.drive_apache_spawner")

#pragma comment(linker, "/export:drive_asl=metamod_org.drive_asl")

#pragma comment(linker, "/export:drive_assassin=metamod_org.drive_assassin")

#pragma comment(linker, "/export:drive_assassin_spawner=metamod_org.drive_assassin_spawner")

#pragma comment(linker, "/export:drive_bm=metamod_org.drive_bm")

#pragma comment(linker, "/export:drive_bm_spawner=metamod_org.drive_bm_spawner")

#pragma comment(linker, "/export:drive_bullsquid=metamod_org.drive_bullsquid")

#pragma comment(linker, "/export:drive_bullsquid_spawner=metamod_org.drive_bullsquid_spawner")

#pragma comment(linker, "/export:drive_chumtoad=metamod_org.drive_chumtoad")

#pragma comment(linker, "/export:drive_controller=metamod_org.drive_controller")

#pragma comment(linker, "/export:drive_controller_spawner=metamod_org.drive_controller_spawner")

#pragma comment(linker, "/export:drive_garg=metamod_org.drive_garg")

#pragma comment(linker, "/export:drive_garg_spawner=metamod_org.drive_garg_spawner")

#pragma comment(linker, "/export:drive_headcrab=metamod_org.drive_headcrab")

#pragma comment(linker, "/export:drive_houndeye=metamod_org.drive_houndeye")

#pragma comment(linker, "/export:drive_houndeye_spawner=metamod_org.drive_houndeye_spawner")

#pragma comment(linker, "/export:drive_icky=metamod_org.drive_icky")

#pragma comment(linker, "/export:drive_icky_spawner=metamod_org.drive_icky_spawner")

#pragma comment(linker, "/export:drive_panth=metamod_org.drive_panth")

#pragma comment(linker, "/export:drive_panth_spawner=metamod_org.drive_panth_spawner")

#pragma comment(linker, "/export:drive_slave_spawner=metamod_org.drive_slave_spawner")

#pragma comment(linker, "/export:drive_turret=metamod_org.drive_turret")

#pragma comment(linker, "/export:drive_turret_spawner=metamod_org.drive_turret_spawner")

#pragma comment(linker, "/export:drop_bomb=metamod_org.drop_bomb")

#pragma comment(linker, "/export:drunkcurse=metamod_org.drunkcurse")

#pragma comment(linker, "/export:drv_hvr_rocket=metamod_org.drv_hvr_rocket")

#pragma comment(linker, "/export:eagle_laser=metamod_org.eagle_laser")

#pragma comment(linker, "/export:effect_shield=metamod_org.effect_shield")

#pragma comment(linker, "/export:egon_mirv=metamod_org.egon_mirv")

#pragma comment(linker, "/export:emp_cannister=metamod_org.emp_cannister")

#pragma comment(linker, "/export:emp_pulse=metamod_org.emp_pulse")

#pragma comment(linker, "/export:entity_botcam=metamod_org.entity_botcam")

#pragma comment(linker, "/export:entity_clustergod=metamod_org.entity_clustergod")

#pragma comment(linker, "/export:entity_digitgod=metamod_org.entity_digitgod")

#pragma comment(linker, "/export:entity_spawn_round=metamod_org.entity_spawn_round")

#pragma comment(linker, "/export:entity_spritegod=metamod_org.entity_spritegod")

#pragma comment(linker, "/export:entity_volcanospew=metamod_org.entity_volcanospew")

#pragma comment(linker, "/export:env_ClusterExplosion=metamod_org.env_ClusterExplosion")

#pragma comment(linker, "/export:env_animsprite=metamod_org.env_animsprite")

#pragma comment(linker, "/export:env_beam=metamod_org.env_beam")

#pragma comment(linker, "/export:env_beamtrail=metamod_org.env_beamtrail")

#pragma comment(linker, "/export:env_beverage=metamod_org.env_beverage")

#pragma comment(linker, "/export:env_blood=metamod_org.env_blood")

#pragma comment(linker, "/export:env_blowercannon=metamod_org.env_blowercannon")

#pragma comment(linker, "/export:env_bombglow=metamod_org.env_bombglow")

#pragma comment(linker, "/export:env_bubbles=metamod_org.env_bubbles")

#pragma comment(linker, "/export:env_customize=metamod_org.env_customize")

#pragma comment(linker, "/export:env_debris=metamod_org.env_debris")

#pragma comment(linker, "/export:env_decal=metamod_org.env_decal")

#pragma comment(linker, "/export:env_dlight=metamod_org.env_dlight")

#pragma comment(linker, "/export:env_electrified_wire=metamod_org.env_electrified_wire")

#pragma comment(linker, "/export:env_elight=metamod_org.env_elight")

#pragma comment(linker, "/export:env_explosion=metamod_org.env_explosion")

#pragma comment(linker, "/export:env_fade=metamod_org.env_fade")

#pragma comment(linker, "/export:env_fadeone=metamod_org.env_fadeone")

#pragma comment(linker, "/export:env_fire=metamod_org.env_fire")

#pragma comment(linker, "/export:env_flag=metamod_org.env_flag")

#pragma comment(linker, "/export:env_fog=metamod_org.env_fog")

#pragma comment(linker, "/export:env_footsteps=metamod_org.env_footsteps")

#pragma comment(linker, "/export:env_fountain=metamod_org.env_fountain")

#pragma comment(linker, "/export:env_funnel=metamod_org.env_funnel")

#pragma comment(linker, "/export:env_gamma=metamod_org.env_gamma")

#pragma comment(linker, "/export:env_genewormcloud=metamod_org.env_genewormcloud")

#pragma comment(linker, "/export:env_genewormspawn=metamod_org.env_genewormspawn")

#pragma comment(linker, "/export:env_global=metamod_org.env_global")

#pragma comment(linker, "/export:env_glow=metamod_org.env_glow")

#pragma comment(linker, "/export:env_laser=metamod_org.env_laser")

#pragma comment(linker, "/export:env_lensflare=metamod_org.env_lensflare")

#pragma comment(linker, "/export:env_lightning=metamod_org.env_lightning")

#pragma comment(linker, "/export:env_message=metamod_org.env_message")

#pragma comment(linker, "/export:env_model=metamod_org.env_model")

#pragma comment(linker, "/export:env_mp3=metamod_org.env_mp3")

#pragma comment(linker, "/export:env_music=metamod_org.env_music")

#pragma comment(linker, "/export:env_particle=metamod_org.env_particle")

#pragma comment(linker, "/export:env_particleemitter=metamod_org.env_particleemitter")

#pragma comment(linker, "/export:env_particles=metamod_org.env_particles")

#pragma comment(linker, "/export:env_particles_custom=metamod_org.env_particles_custom")

#pragma comment(linker, "/export:env_particule=metamod_org.env_particule")

#pragma comment(linker, "/export:env_precip=metamod_org.env_precip")

#pragma comment(linker, "/export:env_push=metamod_org.env_push")

#pragma comment(linker, "/export:env_quakefx=metamod_org.env_quakefx")

#pragma comment(linker, "/export:env_rain=metamod_org.env_rain")

#pragma comment(linker, "/export:env_render=metamod_org.env_render")

#pragma comment(linker, "/export:env_rocketshooter=metamod_org.env_rocketshooter")

#pragma comment(linker, "/export:env_rope=metamod_org.env_rope")

#pragma comment(linker, "/export:env_sentence=metamod_org.env_sentence")

#pragma comment(linker, "/export:env_shake=metamod_org.env_shake")

#pragma comment(linker, "/export:env_shockwave=metamod_org.env_shockwave")

#pragma comment(linker, "/export:env_shooter=metamod_org.env_shooter")

#pragma comment(linker, "/export:env_sky=metamod_org.env_sky")

#pragma comment(linker, "/export:env_smoker=metamod_org.env_smoker")

#pragma comment(linker, "/export:env_snow=metamod_org.env_snow")

#pragma comment(linker, "/export:env_sound=metamod_org.env_sound")

#pragma comment(linker, "/export:env_spark=metamod_org.env_spark")

#pragma comment(linker, "/export:env_spawnereffect=metamod_org.env_spawnereffect")

#pragma comment(linker, "/export:env_sprite=metamod_org.env_sprite")

#pragma comment(linker, "/export:env_spriteshooter=metamod_org.env_spriteshooter")

#pragma comment(linker, "/export:env_spritetrain=metamod_org.env_spritetrain")

#pragma comment(linker, "/export:env_state=metamod_org.env_state")

#pragma comment(linker, "/export:env_sun=metamod_org.env_sun")

#pragma comment(linker, "/export:env_timer=metamod_org.env_timer")

#pragma comment(linker, "/export:env_vgui=metamod_org.env_vgui")

#pragma comment(linker, "/export:env_warpball=metamod_org.env_warpball")

#pragma comment(linker, "/export:env_weather=metamod_org.env_weather")

#pragma comment(linker, "/export:env_xenmaker=metamod_org.env_xenmaker")

#pragma comment(linker, "/export:equipment_parachute=metamod_org.equipment_parachute")

#pragma comment(linker, "/export:event_player_die=metamod_org.event_player_die")

#pragma comment(linker, "/export:event_player_join=metamod_org.event_player_join")

#pragma comment(linker, "/export:event_player_kill=metamod_org.event_player_kill")

#pragma comment(linker, "/export:event_player_leave=metamod_org.event_player_leave")

#pragma comment(linker, "/export:event_player_spawn=metamod_org.event_player_spawn")

#pragma comment(linker, "/export:event_round_end=metamod_org.event_round_end")

#pragma comment(linker, "/export:event_round_prestart=metamod_org.event_round_prestart")

#pragma comment(linker, "/export:event_round_reset=metamod_org.event_round_reset")

#pragma comment(linker, "/export:event_round_start=metamod_org.event_round_start")

#pragma comment(linker, "/export:event_team_die=metamod_org.event_team_die")

#pragma comment(linker, "/export:event_team_win=metamod_org.event_team_win")

#pragma comment(linker, "/export:explode_bolt=metamod_org.explode_bolt")

#pragma comment(linker, "/export:explodingattack=metamod_org.explodingattack")

#pragma comment(linker, "/export:explosive_slug=metamod_org.explosive_slug")

#pragma comment(linker, "/export:external_cam=metamod_org.external_cam")

#pragma comment(linker, "/export:extra_ammo=metamod_org.extra_ammo")

#pragma comment(linker, "/export:fa_drop_zone=metamod_org.fa_drop_zone")

#pragma comment(linker, "/export:fa_parachute=metamod_org.fa_parachute")

#pragma comment(linker, "/export:fa_push_flag=metamod_org.fa_push_flag")

#pragma comment(linker, "/export:fa_push_point=metamod_org.fa_push_point")

#pragma comment(linker, "/export:fa_sd_object=metamod_org.fa_sd_object")

#pragma comment(linker, "/export:fa_team_goal=metamod_org.fa_team_goal")

#pragma comment(linker, "/export:fa_team_item=metamod_org.fa_team_item")

#pragma comment(linker, "/export:fading_corpse=metamod_org.fading_corpse")

#pragma comment(linker, "/export:fev_cloud=metamod_org.fev_cloud")

#pragma comment(linker, "/export:fev_vial=metamod_org.fev_vial")

#pragma comment(linker, "/export:final_flash=metamod_org.final_flash")

#pragma comment(linker, "/export:finish=metamod_org.finish")

#pragma comment(linker, "/export:fire_ball=metamod_org.fire_ball")

#pragma comment(linker, "/export:fireanddie=metamod_org.fireanddie")

#pragma comment(linker, "/export:firework=metamod_org.firework")

#pragma comment(linker, "/export:flag=metamod_org.flag")

#pragma comment(linker, "/export:flag_capture_point=metamod_org.flag_capture_point")

#pragma comment(linker, "/export:flag_follow=metamod_org.flag_follow")

#pragma comment(linker, "/export:flag_world=metamod_org.flag_world")

#pragma comment(linker, "/export:flak_bomb=metamod_org.flak_bomb")

#pragma comment(linker, "/export:flak_grenade=metamod_org.flak_grenade")

#pragma comment(linker, "/export:flak_shard=metamod_org.flak_shard")

#pragma comment(linker, "/export:flakfrag=metamod_org.flakfrag")

#pragma comment(linker, "/export:flame=metamod_org.flame")

#pragma comment(linker, "/export:flame_ball=metamod_org.flame_ball")

#pragma comment(linker, "/export:flame_chunk=metamod_org.flame_chunk")

#pragma comment(linker, "/export:flamme=metamod_org.flamme")

#pragma comment(linker, "/export:flare=metamod_org.flare")

#pragma comment(linker, "/export:flare_fire=metamod_org.flare_fire")

#pragma comment(linker, "/export:flying_axe=metamod_org.flying_axe")

#pragma comment(linker, "/export:flying_crowbar=metamod_org.flying_crowbar")

#pragma comment(linker, "/export:fog=metamod_org.fog")

#pragma comment(linker, "/export:follow_ent=metamod_org.follow_ent")

#pragma comment(linker, "/export:followbot=metamod_org.followbot")

#pragma comment(linker, "/export:follower_basic=metamod_org.follower_basic")

#pragma comment(linker, "/export:football=metamod_org.football")

#pragma comment(linker, "/export:frag_grenade=metamod_org.frag_grenade")

#pragma comment(linker, "/export:freeze_beam=metamod_org.freeze_beam")

#pragma comment(linker, "/export:freeze_gel=metamod_org.freeze_gel")

#pragma comment(linker, "/export:freeze_grenade=metamod_org.freeze_grenade")

#pragma comment(linker, "/export:freeze_timer=metamod_org.freeze_timer")

#pragma comment(linker, "/export:friction_timer=metamod_org.friction_timer")

#pragma comment(linker, "/export:frostball=metamod_org.frostball")

#pragma comment(linker, "/export:fruit_sacrifice_point_team_green=metamod_org.fruit_sacrifice_point_team_green")

#pragma comment(linker, "/export:fruit_sacrifice_point_team_red=metamod_org.fruit_sacrifice_point_team_red")

#pragma comment(linker, "/export:func_airstrike_area=metamod_org.func_airstrike_area")

#pragma comment(linker, "/export:func_ammoprovider=metamod_org.func_ammoprovider")

#pragma comment(linker, "/export:func_ammostripper=metamod_org.func_ammostripper")

#pragma comment(linker, "/export:func_bankteller=metamod_org.func_bankteller")

#pragma comment(linker, "/export:func_base=metamod_org.func_base")

#pragma comment(linker, "/export:func_bomb_target=metamod_org.func_bomb_target")

#pragma comment(linker, "/export:func_breakable=metamod_org.func_breakable")

#pragma comment(linker, "/export:func_breakpoints=metamod_org.func_breakpoints")

#pragma comment(linker, "/export:func_button=metamod_org.func_button")

#pragma comment(linker, "/export:func_buyzone=metamod_org.func_buyzone")

#pragma comment(linker, "/export:func_capture_area=metamod_org.func_capture_area")

#pragma comment(linker, "/export:func_capturepoint=metamod_org.func_capturepoint")

#pragma comment(linker, "/export:func_clouds=metamod_org.func_clouds")

#pragma comment(linker, "/export:func_conveyor=metamod_org.func_conveyor")

#pragma comment(linker, "/export:func_corruptsecurity=metamod_org.func_corruptsecurity")

#pragma comment(linker, "/export:func_ctb=metamod_org.func_ctb")

#pragma comment(linker, "/export:func_destroy_objective=metamod_org.func_destroy_objective")

#pragma comment(linker, "/export:func_disctoggle=metamod_org.func_disctoggle")

#pragma comment(linker, "/export:func_door=metamod_org.func_door")

#pragma comment(linker, "/export:func_door2=metamod_org.func_door2")

#pragma comment(linker, "/export:func_door_rotating=metamod_org.func_door_rotating")

#pragma comment(linker, "/export:func_elevator=metamod_org.func_elevator")

#pragma comment(linker, "/export:func_escapezone=metamod_org.func_escapezone")

#pragma comment(linker, "/export:func_friction=metamod_org.func_friction")

#pragma comment(linker, "/export:func_goal_zone=metamod_org.func_goal_zone")

#pragma comment(linker, "/export:func_goalpoint=metamod_org.func_goalpoint")

#pragma comment(linker, "/export:func_golem_body=metamod_org.func_golem_body")

#pragma comment(linker, "/export:func_golem_controls_attack=metamod_org.func_golem_controls_attack")

#pragma comment(linker, "/export:func_golem_controls_forward=metamod_org.func_golem_controls_forward")

#pragma comment(linker, "/export:func_golem_controls_left=metamod_org.func_golem_controls_left")

#pragma comment(linker, "/export:func_golem_controls_right=metamod_org.func_golem_controls_right")

#pragma comment(linker, "/export:func_golem_leftarm=metamod_org.func_golem_leftarm")

#pragma comment(linker, "/export:func_golem_leftleg=metamod_org.func_golem_leftleg")

#pragma comment(linker, "/export:func_golem_rightarm=metamod_org.func_golem_rightarm")

#pragma comment(linker, "/export:func_golem_rightleg=metamod_org.func_golem_rightleg")

#pragma comment(linker, "/export:func_grencatch=metamod_org.func_grencatch")

#pragma comment(linker, "/export:func_guntarget=metamod_org.func_guntarget")

#pragma comment(linker, "/export:func_healthcharger=metamod_org.func_healthcharger")

#pragma comment(linker, "/export:func_hostage_rescue=metamod_org.func_hostage_rescue")

#pragma comment(linker, "/export:func_illusionary=metamod_org.func_illusionary")

#pragma comment(linker, "/export:func_jail_breakable=metamod_org.func_jail_breakable")

#pragma comment(linker, "/export:func_jail_button=metamod_org.func_jail_button")

#pragma comment(linker, "/export:func_jail_door=metamod_org.func_jail_door")

#pragma comment(linker, "/export:func_jail_door_rotating=metamod_org.func_jail_door_rotating")

#pragma comment(linker, "/export:func_jail_pushable=metamod_org.func_jail_pushable")

#pragma comment(linker, "/export:func_jail_release=metamod_org.func_jail_release")

#pragma comment(linker, "/export:func_ladder=metamod_org.func_ladder")

#pragma comment(linker, "/export:func_laddertype=metamod_org.func_laddertype")

#pragma comment(linker, "/export:func_land_transport=metamod_org.func_land_transport")

#pragma comment(linker, "/export:func_landtransport=metamod_org.func_landtransport")

#pragma comment(linker, "/export:func_modeltank=metamod_org.func_modeltank")

#pragma comment(linker, "/export:func_modelvehicle=metamod_org.func_modelvehicle")

#pragma comment(linker, "/export:func_modelvehiclemodel=metamod_org.func_modelvehiclemodel")

#pragma comment(linker, "/export:func_monsterclip=metamod_org.func_monsterclip")

#pragma comment(linker, "/export:func_mortar_field=metamod_org.func_mortar_field")

#pragma comment(linker, "/export:func_music=metamod_org.func_music")

#pragma comment(linker, "/export:func_needs=metamod_org.func_needs")

#pragma comment(linker, "/export:func_needs_boredom=metamod_org.func_needs_boredom")

#pragma comment(linker, "/export:func_needs_dirty=metamod_org.func_needs_dirty")

#pragma comment(linker, "/export:func_needs_drink=metamod_org.func_needs_drink")

#pragma comment(linker, "/export:func_needs_eat=metamod_org.func_needs_eat")

#pragma comment(linker, "/export:func_needs_fatigue=metamod_org.func_needs_fatigue")

#pragma comment(linker, "/export:func_needs_lonely=metamod_org.func_needs_lonely")

#pragma comment(linker, "/export:func_needs_pee=metamod_org.func_needs_pee")

#pragma comment(linker, "/export:func_needs_poo=metamod_org.func_needs_poo")

#pragma comment(linker, "/export:func_nobuild=metamod_org.func_nobuild")

#pragma comment(linker, "/export:func_nogrenades=metamod_org.func_nogrenades")

#pragma comment(linker, "/export:func_op4mortarcontroller=metamod_org.func_op4mortarcontroller")

#pragma comment(linker, "/export:func_particle_system=metamod_org.func_particle_system")

#pragma comment(linker, "/export:func_pendulum=metamod_org.func_pendulum")

#pragma comment(linker, "/export:func_physics=metamod_org.func_physics")

#pragma comment(linker, "/export:func_pillageable=metamod_org.func_pillageable")

#pragma comment(linker, "/export:func_plat=metamod_org.func_plat")

#pragma comment(linker, "/export:func_plat_toggleremove=metamod_org.func_plat_toggleremove")

#pragma comment(linker, "/export:func_platrot=metamod_org.func_platrot")

#pragma comment(linker, "/export:func_player_start=metamod_org.func_player_start")

#pragma comment(linker, "/export:func_point=metamod_org.func_point")

#pragma comment(linker, "/export:func_possesion=metamod_org.func_possesion")

#pragma comment(linker, "/export:func_protect=metamod_org.func_protect")

#pragma comment(linker, "/export:func_pushable=metamod_org.func_pushable")

#pragma comment(linker, "/export:func_rain=metamod_org.func_rain")

#pragma comment(linker, "/export:func_recharge=metamod_org.func_recharge")

#pragma comment(linker, "/export:func_reset=metamod_org.func_reset")

#pragma comment(linker, "/export:func_resource=metamod_org.func_resource")

#pragma comment(linker, "/export:func_rot_button=metamod_org.func_rot_button")

#pragma comment(linker, "/export:func_rotating=metamod_org.func_rotating")

#pragma comment(linker, "/export:func_searchlight=metamod_org.func_searchlight")

#pragma comment(linker, "/export:func_securityzone=metamod_org.func_securityzone")

#pragma comment(linker, "/export:func_seethrough=metamod_org.func_seethrough")

#pragma comment(linker, "/export:func_seethroughdoor=metamod_org.func_seethroughdoor")

#pragma comment(linker, "/export:func_shine=metamod_org.func_shine")

#pragma comment(linker, "/export:func_sickbay_bed=metamod_org.func_sickbay_bed")

#pragma comment(linker, "/export:func_sickbay_psych=metamod_org.func_sickbay_psych")

#pragma comment(linker, "/export:func_snow=metamod_org.func_snow")

#pragma comment(linker, "/export:func_tank=metamod_org.func_tank")

#pragma comment(linker, "/export:func_tank_gauss=metamod_org.func_tank_gauss")

#pragma comment(linker, "/export:func_tank_of=metamod_org.func_tank_of")

#pragma comment(linker, "/export:func_tank_turret=metamod_org.func_tank_turret")

#pragma comment(linker, "/export:func_tankbase=metamod_org.func_tankbase")

#pragma comment(linker, "/export:func_tankcannon=metamod_org.func_tankcannon")

#pragma comment(linker, "/export:func_tankcontrols=metamod_org.func_tankcontrols")

#pragma comment(linker, "/export:func_tankcontrols_of=metamod_org.func_tankcontrols_of")

#pragma comment(linker, "/export:func_tankdrive=metamod_org.func_tankdrive")

#pragma comment(linker, "/export:func_tankgib=metamod_org.func_tankgib")

#pragma comment(linker, "/export:func_tankgib_gib=metamod_org.func_tankgib_gib")

#pragma comment(linker, "/export:func_tankgoauld=metamod_org.func_tankgoauld")

#pragma comment(linker, "/export:func_tanklaser=metamod_org.func_tanklaser")

#pragma comment(linker, "/export:func_tanklaser_of=metamod_org.func_tanklaser_of")

#pragma comment(linker, "/export:func_tankmg=metamod_org.func_tankmg")

#pragma comment(linker, "/export:func_tankmortar=metamod_org.func_tankmortar")

#pragma comment(linker, "/export:func_tankmortar_of=metamod_org.func_tankmortar_of")

#pragma comment(linker, "/export:func_tankrocket=metamod_org.func_tankrocket")

#pragma comment(linker, "/export:func_tankrocket_of=metamod_org.func_tankrocket_of")

#pragma comment(linker, "/export:func_tanktarget=metamod_org.func_tanktarget")

#pragma comment(linker, "/export:func_tbutton=metamod_org.func_tbutton")

#pragma comment(linker, "/export:func_tech_breakable=metamod_org.func_tech_breakable")

#pragma comment(linker, "/export:func_trackautochange=metamod_org.func_trackautochange")

#pragma comment(linker, "/export:func_trackchange=metamod_org.func_trackchange")

#pragma comment(linker, "/export:func_tracktrain=metamod_org.func_tracktrain")

#pragma comment(linker, "/export:func_train=metamod_org.func_train")

#pragma comment(linker, "/export:func_traincontrols=metamod_org.func_traincontrols")

#pragma comment(linker, "/export:func_trenchcap1=metamod_org.func_trenchcap1")

#pragma comment(linker, "/export:func_trenchcap2=metamod_org.func_trenchcap2")

#pragma comment(linker, "/export:func_trenchcap3=metamod_org.func_trenchcap3")

#pragma comment(linker, "/export:func_trenchcap4=metamod_org.func_trenchcap4")

#pragma comment(linker, "/export:func_use=metamod_org.func_use")

#pragma comment(linker, "/export:func_vehicle=metamod_org.func_vehicle")

#pragma comment(linker, "/export:func_vehiclecontrols=metamod_org.func_vehiclecontrols")

#pragma comment(linker, "/export:func_vehicletankcontrols=metamod_org.func_vehicletankcontrols")

#pragma comment(linker, "/export:func_vine=metamod_org.func_vine")

#pragma comment(linker, "/export:func_vip_safetyzone=metamod_org.func_vip_safetyzone")

#pragma comment(linker, "/export:func_wall=metamod_org.func_wall")

#pragma comment(linker, "/export:func_wall_toggle=metamod_org.func_wall_toggle")

#pragma comment(linker, "/export:func_wardrobe=metamod_org.func_wardrobe")

#pragma comment(linker, "/export:func_water=metamod_org.func_water")

#pragma comment(linker, "/export:func_water_up=metamod_org.func_water_up")

#pragma comment(linker, "/export:func_weaponcheck=metamod_org.func_weaponcheck")

#pragma comment(linker, "/export:func_weldable=metamod_org.func_weldable")

#pragma comment(linker, "/export:func_wind=metamod_org.func_wind")

#pragma comment(linker, "/export:game_clock=metamod_org.game_clock")

#pragma comment(linker, "/export:game_counter=metamod_org.game_counter")

#pragma comment(linker, "/export:game_counter_set=metamod_org.game_counter_set")

#pragma comment(linker, "/export:game_end=metamod_org.game_end")

#pragma comment(linker, "/export:game_endbattle=metamod_org.game_endbattle")

#pragma comment(linker, "/export:game_item=metamod_org.game_item")

#pragma comment(linker, "/export:game_levelmusic=metamod_org.game_levelmusic")

#pragma comment(linker, "/export:game_nuke=metamod_org.game_nuke")

#pragma comment(linker, "/export:game_player_die=metamod_org.game_player_die")

#pragma comment(linker, "/export:game_player_equip=metamod_org.game_player_equip")

#pragma comment(linker, "/export:game_player_hurt=metamod_org.game_player_hurt")

#pragma comment(linker, "/export:game_player_message=metamod_org.game_player_message")

#pragma comment(linker, "/export:game_player_team=metamod_org.game_player_team")

#pragma comment(linker, "/export:game_playerdie=metamod_org.game_playerdie")

#pragma comment(linker, "/export:game_roundend=metamod_org.game_roundend")

#pragma comment(linker, "/export:game_score=metamod_org.game_score")

#pragma comment(linker, "/export:game_team_master=metamod_org.game_team_master")

#pragma comment(linker, "/export:game_team_score=metamod_org.game_team_score")

#pragma comment(linker, "/export:game_team_set=metamod_org.game_team_set")

#pragma comment(linker, "/export:game_team_win=metamod_org.game_team_win")

#pragma comment(linker, "/export:game_text=metamod_org.game_text")

#pragma comment(linker, "/export:game_zone_pirscore=metamod_org.game_zone_pirscore")

#pragma comment(linker, "/export:game_zone_player=metamod_org.game_zone_player")

#pragma comment(linker, "/export:game_zone_territory=metamod_org.game_zone_territory")

#pragma comment(linker, "/export:game_zone_vikscore=metamod_org.game_zone_vikscore")

#pragma comment(linker, "/export:gameclock=metamod_org.gameclock")

#pragma comment(linker, "/export:garg_hull=metamod_org.garg_hull")

#pragma comment(linker, "/export:garg_stomp=metamod_org.garg_stomp")

#pragma comment(linker, "/export:gauss_becon=metamod_org.gauss_becon")

#pragma comment(linker, "/export:generic_model=metamod_org.generic_model")

#pragma comment(linker, "/export:getGlobalStunLevel=metamod_org.getGlobalStunLevel")

#pragma comment(linker, "/export:ghost=metamod_org.ghost")

#pragma comment(linker, "/export:gibable_corpse=metamod_org.gibable_corpse")

#pragma comment(linker, "/export:gibshooter=metamod_org.gibshooter")

#pragma comment(linker, "/export:glock_gib=metamod_org.glock_gib")

#pragma comment(linker, "/export:glock_stickygib=metamod_org.glock_stickygib")

#pragma comment(linker, "/export:gluon=metamod_org.gluon")

#pragma comment(linker, "/export:gluon2=metamod_org.gluon2")

#pragma comment(linker, "/export:gonarch_headcrabifier=metamod_org.gonarch_headcrabifier")

#pragma comment(linker, "/export:gonomeguts=metamod_org.gonomeguts")

#pragma comment(linker, "/export:gonomespit=metamod_org.gonomespit")

#pragma comment(linker, "/export:gr_shell=metamod_org.gr_shell")

#pragma comment(linker, "/export:grapple_bolt=metamod_org.grapple_bolt")

#pragma comment(linker, "/export:grapple_hook=metamod_org.grapple_hook")

#pragma comment(linker, "/export:grapple_tip=metamod_org.grapple_tip")

#pragma comment(linker, "/export:grappletongue=metamod_org.grappletongue")

#pragma comment(linker, "/export:gravity_grenade=metamod_org.gravity_grenade")

#pragma comment(linker, "/export:gren_projectile=metamod_org.gren_projectile")

#pragma comment(linker, "/export:gren_smoke=metamod_org.gren_smoke")

#pragma comment(linker, "/export:grenade=metamod_org.grenade")

#pragma comment(linker, "/export:guard_info=metamod_org.guard_info")

#pragma comment(linker, "/export:guidedattack=metamod_org.guidedattack")

#pragma comment(linker, "/export:gunmancycler=metamod_org.gunmancycler")

#pragma comment(linker, "/export:hallucgrenade=metamod_org.hallucgrenade")

#pragma comment(linker, "/export:halo_base=metamod_org.halo_base")

#pragma comment(linker, "/export:hand_knife=metamod_org.hand_knife")

#pragma comment(linker, "/export:he_charge_flare=metamod_org.he_charge_flare")

#pragma comment(linker, "/export:he_eye_flare=metamod_org.he_eye_flare")

#pragma comment(linker, "/export:headcrab_teather=metamod_org.headcrab_teather")

#pragma comment(linker, "/export:hegrenade=metamod_org.hegrenade")

#pragma comment(linker, "/export:hellfire=metamod_org.hellfire")

#pragma comment(linker, "/export:hi_bomb_zone=metamod_org.hi_bomb_zone")

#pragma comment(linker, "/export:hi_button_load=metamod_org.hi_button_load")

#pragma comment(linker, "/export:hi_coop_tango=metamod_org.hi_coop_tango")

#pragma comment(linker, "/export:hi_fog=metamod_org.hi_fog")

#pragma comment(linker, "/export:hi_global=metamod_org.hi_global")

#pragma comment(linker, "/export:hi_hostage=metamod_org.hi_hostage")

#pragma comment(linker, "/export:hi_hostage_rescue=metamod_org.hi_hostage_rescue")

#pragma comment(linker, "/export:hi_hostage_respawn=metamod_org.hi_hostage_respawn")

#pragma comment(linker, "/export:hi_nameposition=metamod_org.hi_nameposition")

#pragma comment(linker, "/export:hi_objective=metamod_org.hi_objective")

#pragma comment(linker, "/export:hi_objective_manager=metamod_org.hi_objective_manager")

#pragma comment(linker, "/export:hi_round_timer=metamod_org.hi_round_timer")

#pragma comment(linker, "/export:hi_spawn_hostage=metamod_org.hi_spawn_hostage")

#pragma comment(linker, "/export:hi_spawn_nato=metamod_org.hi_spawn_nato")

#pragma comment(linker, "/export:hi_spawn_observer=metamod_org.hi_spawn_observer")

#pragma comment(linker, "/export:hi_spawn_tango=metamod_org.hi_spawn_tango")

#pragma comment(linker, "/export:hlight=metamod_org.hlight")

#pragma comment(linker, "/export:hltr_assaut_boutton=metamod_org.hltr_assaut_boutton")

#pragma comment(linker, "/export:hltr_hostage=metamod_org.hltr_hostage")

#pragma comment(linker, "/export:hltr_object=metamod_org.hltr_object")

#pragma comment(linker, "/export:hltr_object_tombe=metamod_org.hltr_object_tombe")

#pragma comment(linker, "/export:hltr_objectcapture=metamod_org.hltr_objectcapture")

#pragma comment(linker, "/export:hltr_objectif=metamod_org.hltr_objectif")

#pragma comment(linker, "/export:hltr_objectif_num=metamod_org.hltr_objectif_num")

#pragma comment(linker, "/export:hltr_passant=metamod_org.hltr_passant")

#pragma comment(linker, "/export:hltr_spectator_start=metamod_org.hltr_spectator_start")

#pragma comment(linker, "/export:hltr_turret=metamod_org.hltr_turret")

#pragma comment(linker, "/export:hltr_waypoint=metamod_org.hltr_waypoint")

#pragma comment(linker, "/export:holo_player=metamod_org.holo_player")

#pragma comment(linker, "/export:hologram_beak=metamod_org.hologram_beak")

#pragma comment(linker, "/export:hologram_damage=metamod_org.hologram_damage")

#pragma comment(linker, "/export:holywars_rocket=metamod_org.holywars_rocket")

#pragma comment(linker, "/export:homing_balls=metamod_org.homing_balls")

#pragma comment(linker, "/export:hornet=metamod_org.hornet")

#pragma comment(linker, "/export:hospital=metamod_org.hospital")

#pragma comment(linker, "/export:hostage_entity=metamod_org.hostage_entity")

#pragma comment(linker, "/export:hud_sprite=metamod_org.hud_sprite")

#pragma comment(linker, "/export:human_flashgrenade=metamod_org.human_flashgrenade")

#pragma comment(linker, "/export:hvr_blkop_rocket=metamod_org.hvr_blkop_rocket")

#pragma comment(linker, "/export:hvr_rocket=metamod_org.hvr_rocket")

#pragma comment(linker, "/export:i_p_t=metamod_org.i_p_t")

#pragma comment(linker, "/export:i_t_g=metamod_org.i_t_g")

#pragma comment(linker, "/export:i_t_t=metamod_org.i_t_t")

#pragma comment(linker, "/export:i_w_g=metamod_org.i_w_g")

#pragma comment(linker, "/export:i_w_t=metamod_org.i_w_t")

#pragma comment(linker, "/export:iflame=metamod_org.iflame")

#pragma comment(linker, "/export:impact_sprite=metamod_org.impact_sprite")

#pragma comment(linker, "/export:impail_arrow=metamod_org.impail_arrow")

#pragma comment(linker, "/export:impailer=metamod_org.impailer")

#pragma comment(linker, "/export:impgren=metamod_org.impgren")

#pragma comment(linker, "/export:implode_timer=metamod_org.implode_timer")

#pragma comment(linker, "/export:in_shell=metamod_org.in_shell")

#pragma comment(linker, "/export:incendiary_rocket=metamod_org.incendiary_rocket")

#pragma comment(linker, "/export:indian_arrow=metamod_org.indian_arrow")

#pragma comment(linker, "/export:infect=metamod_org.infect")

#pragma comment(linker, "/export:info_Waterdetect=metamod_org.info_Waterdetect")

#pragma comment(linker, "/export:info_administrator=metamod_org.info_administrator")

#pragma comment(linker, "/export:info_airstrike_node=metamod_org.info_airstrike_node")

#pragma comment(linker, "/export:info_alarm=metamod_org.info_alarm")

#pragma comment(linker, "/export:info_alias=metamod_org.info_alias")

#pragma comment(linker, "/export:info_alien_return=metamod_org.info_alien_return")

#pragma comment(linker, "/export:info_alien_start=metamod_org.info_alien_start")

#pragma comment(linker, "/export:info_american_line=metamod_org.info_american_line")

#pragma comment(linker, "/export:info_areadef=metamod_org.info_areadef")

#pragma comment(linker, "/export:info_areamarker=metamod_org.info_areamarker")

#pragma comment(linker, "/export:info_ball_start=metamod_org.info_ball_start")

#pragma comment(linker, "/export:info_banana_green_capture=metamod_org.info_banana_green_capture")

#pragma comment(linker, "/export:info_banana_red_capture=metamod_org.info_banana_red_capture")

#pragma comment(linker, "/export:info_bananier=metamod_org.info_bananier")

#pragma comment(linker, "/export:info_bg_detect=metamod_org.info_bg_detect")

#pragma comment(linker, "/export:info_bigmomma=metamod_org.info_bigmomma")

#pragma comment(linker, "/export:info_bomb_target=metamod_org.info_bomb_target")

#pragma comment(linker, "/export:info_bone=metamod_org.info_bone")

#pragma comment(linker, "/export:info_bone_spawn=metamod_org.info_bone_spawn")

#pragma comment(linker, "/export:info_boobytrap=metamod_org.info_boobytrap")

#pragma comment(linker, "/export:info_botlandmark=metamod_org.info_botlandmark")

#pragma comment(linker, "/export:info_botnode=metamod_org.info_botnode")

#pragma comment(linker, "/export:info_british_line=metamod_org.info_british_line")

#pragma comment(linker, "/export:info_button_phonebooth=metamod_org.info_button_phonebooth")

#pragma comment(linker, "/export:info_caisse_128=metamod_org.info_caisse_128")

#pragma comment(linker, "/export:info_caisse_16=metamod_org.info_caisse_16")

#pragma comment(linker, "/export:info_caisse_256=metamod_org.info_caisse_256")

#pragma comment(linker, "/export:info_caisse_32=metamod_org.info_caisse_32")

#pragma comment(linker, "/export:info_caisse_64=metamod_org.info_caisse_64")

#pragma comment(linker, "/export:info_camera=metamod_org.info_camera")

#pragma comment(linker, "/export:info_cap_rules=metamod_org.info_cap_rules")

#pragma comment(linker, "/export:info_checkpoint=metamod_org.info_checkpoint")

#pragma comment(linker, "/export:info_chicken=metamod_org.info_chicken")

#pragma comment(linker, "/export:info_chip=metamod_org.info_chip")

#pragma comment(linker, "/export:info_civ_start=metamod_org.info_civ_start")

#pragma comment(linker, "/export:info_compile_parameters=metamod_org.info_compile_parameters")

#pragma comment(linker, "/export:info_css=metamod_org.info_css")

#pragma comment(linker, "/export:info_ctb_controller=metamod_org.info_ctb_controller")

#pragma comment(linker, "/export:info_ctfdetect=metamod_org.info_ctfdetect")

#pragma comment(linker, "/export:info_ctfspawn=metamod_org.info_ctfspawn")

#pragma comment(linker, "/export:info_ctfspawn_powerup=metamod_org.info_ctfspawn_powerup")

#pragma comment(linker, "/export:info_curtain=metamod_org.info_curtain")

#pragma comment(linker, "/export:info_deathball_spawn=metamod_org.info_deathball_spawn")

#pragma comment(linker, "/export:info_defaultammo=metamod_org.info_defaultammo")

#pragma comment(linker, "/export:info_displacer_earth_target=metamod_org.info_displacer_earth_target")

#pragma comment(linker, "/export:info_displacer_xen_target=metamod_org.info_displacer_xen_target")

#pragma comment(linker, "/export:info_dm=metamod_org.info_dm")

#pragma comment(linker, "/export:info_doddetect=metamod_org.info_doddetect")

#pragma comment(linker, "/export:info_dragonrider_spawn=metamod_org.info_dragonrider_spawn")

#pragma comment(linker, "/export:info_draw_slayerswin=metamod_org.info_draw_slayerswin")

#pragma comment(linker, "/export:info_draw_vampireswin=metamod_org.info_draw_vampireswin")

#pragma comment(linker, "/export:info_drive_agrunt_spawn=metamod_org.info_drive_agrunt_spawn")

#pragma comment(linker, "/export:info_drive_apache_spawn=metamod_org.info_drive_apache_spawn")

#pragma comment(linker, "/export:info_drive_assassin_spawn=metamod_org.info_drive_assassin_spawn")

#pragma comment(linker, "/export:info_drive_bm_spawn=metamod_org.info_drive_bm_spawn")

#pragma comment(linker, "/export:info_drive_bullsquid_spawn=metamod_org.info_drive_bullsquid_spawn")

#pragma comment(linker, "/export:info_drive_controller_spawn=metamod_org.info_drive_controller_spawn")

#pragma comment(linker, "/export:info_drive_garg_spawn=metamod_org.info_drive_garg_spawn")

#pragma comment(linker, "/export:info_drive_houndeye_spawn=metamod_org.info_drive_houndeye_spawn")

#pragma comment(linker, "/export:info_drive_icky_spawn=metamod_org.info_drive_icky_spawn")

#pragma comment(linker, "/export:info_drive_panth_spawn=metamod_org.info_drive_panth_spawn")

#pragma comment(linker, "/export:info_drive_slave_spawn=metamod_org.info_drive_slave_spawn")

#pragma comment(linker, "/export:info_drive_turret_spawn=metamod_org.info_drive_turret_spawn")

#pragma comment(linker, "/export:info_elephant=metamod_org.info_elephant")

#pragma comment(linker, "/export:info_elev_floor=metamod_org.info_elev_floor")

#pragma comment(linker, "/export:info_escape_start=metamod_org.info_escape_start")

#pragma comment(linker, "/export:info_escape_target=metamod_org.info_escape_target")

#pragma comment(linker, "/export:info_evil_start=metamod_org.info_evil_start")

#pragma comment(linker, "/export:info_firearms_detect=metamod_org.info_firearms_detect")

#pragma comment(linker, "/export:info_firstround_spawn=metamod_org.info_firstround_spawn")

#pragma comment(linker, "/export:info_flagspawn=metamod_org.info_flagspawn")

#pragma comment(linker, "/export:info_flash=metamod_org.info_flash")

#pragma comment(linker, "/export:info_frontline=metamod_org.info_frontline")

#pragma comment(linker, "/export:info_gameplay=metamod_org.info_gameplay")

#pragma comment(linker, "/export:info_gameplaylogic=metamod_org.info_gameplaylogic")

#pragma comment(linker, "/export:info_gangsta_dm_start=metamod_org.info_gangsta_dm_start")

#pragma comment(linker, "/export:info_goldeneye=metamod_org.info_goldeneye")

#pragma comment(linker, "/export:info_good_start=metamod_org.info_good_start")

#pragma comment(linker, "/export:info_group=metamod_org.info_group")

#pragma comment(linker, "/export:info_gwGeneral_spawn=metamod_org.info_gwGeneral_spawn")

#pragma comment(linker, "/export:info_gwars_map=metamod_org.info_gwars_map")

#pragma comment(linker, "/export:info_gwbriefing_spawn=metamod_org.info_gwbriefing_spawn")

#pragma comment(linker, "/export:info_gwinmap_spawn=metamod_org.info_gwinmap_spawn")

#pragma comment(linker, "/export:info_gwplayer_spawn=metamod_org.info_gwplayer_spawn")

#pragma comment(linker, "/export:info_gwwaiting_spawn=metamod_org.info_gwwaiting_spawn")

#pragma comment(linker, "/export:info_hlpaintctfdetect=metamod_org.info_hlpaintctfdetect")

#pragma comment(linker, "/export:info_hmctfdetect=metamod_org.info_hmctfdetect")

#pragma comment(linker, "/export:info_hostage_rescue=metamod_org.info_hostage_rescue")

#pragma comment(linker, "/export:info_hostage_safezone=metamod_org.info_hostage_safezone")

#pragma comment(linker, "/export:info_human_return=metamod_org.info_human_return")

#pragma comment(linker, "/export:info_human_start=metamod_org.info_human_start")

#pragma comment(linker, "/export:info_initial_player_allies=metamod_org.info_initial_player_allies")

#pragma comment(linker, "/export:info_initial_player_axis=metamod_org.info_initial_player_axis")

#pragma comment(linker, "/export:info_intermission=metamod_org.info_intermission")

#pragma comment(linker, "/export:info_italian_start=metamod_org.info_italian_start")

#pragma comment(linker, "/export:info_jail_start=metamod_org.info_jail_start")

#pragma comment(linker, "/export:info_join_autoassign=metamod_org.info_join_autoassign")

#pragma comment(linker, "/export:info_join_team=metamod_org.info_join_team")

#pragma comment(linker, "/export:info_jumppad_target=metamod_org.info_jumppad_target")

#pragma comment(linker, "/export:info_jwhite_capture=metamod_org.info_jwhite_capture")

#pragma comment(linker, "/export:info_jwhite_escape=metamod_org.info_jwhite_escape")

#pragma comment(linker, "/export:info_jwhite_rescue=metamod_org.info_jwhite_rescue")

#pragma comment(linker, "/export:info_kb_deathmatch=metamod_org.info_kb_deathmatch")

#pragma comment(linker, "/export:info_lacrymo=metamod_org.info_lacrymo")

#pragma comment(linker, "/export:info_landmark=metamod_org.info_landmark")

#pragma comment(linker, "/export:info_landmine=metamod_org.info_landmine")

#pragma comment(linker, "/export:info_leave_game=metamod_org.info_leave_game")

#pragma comment(linker, "/export:info_location=metamod_org.info_location")

#pragma comment(linker, "/export:info_map_parameters=metamod_org.info_map_parameters")

#pragma comment(linker, "/export:info_mapdetect=metamod_org.info_mapdetect")

#pragma comment(linker, "/export:info_mapinfo=metamod_org.info_mapinfo")

#pragma comment(linker, "/export:info_marguerite=metamod_org.info_marguerite")

#pragma comment(linker, "/export:info_marker=metamod_org.info_marker")

#pragma comment(linker, "/export:info_minefield=metamod_org.info_minefield")

#pragma comment(linker, "/export:info_model=metamod_org.info_model")

#pragma comment(linker, "/export:info_money_start=metamod_org.info_money_start")

#pragma comment(linker, "/export:info_monkey_start_team_green=metamod_org.info_monkey_start_team_green")

#pragma comment(linker, "/export:info_monkey_start_team_red=metamod_org.info_monkey_start_team_red")

#pragma comment(linker, "/export:info_monster_return=metamod_org.info_monster_return")

#pragma comment(linker, "/export:info_monster_start=metamod_org.info_monster_start")

#pragma comment(linker, "/export:info_morbid=metamod_org.info_morbid")

#pragma comment(linker, "/export:info_morbid_start=metamod_org.info_morbid_start")

#pragma comment(linker, "/export:info_movewith=metamod_org.info_movewith")

#pragma comment(linker, "/export:info_msdetect=metamod_org.info_msdetect")

#pragma comment(linker, "/export:info_multiple=metamod_org.info_multiple")

#pragma comment(linker, "/export:info_next_map=metamod_org.info_next_map")

#pragma comment(linker, "/export:info_node=metamod_org.info_node")

#pragma comment(linker, "/export:info_node_air=metamod_org.info_node_air")

#pragma comment(linker, "/export:info_nomines=metamod_org.info_nomines")

#pragma comment(linker, "/export:info_null=metamod_org.info_null")

#pragma comment(linker, "/export:info_objective=metamod_org.info_objective")

#pragma comment(linker, "/export:info_observer=metamod_org.info_observer")

#pragma comment(linker, "/export:info_observer_start=metamod_org.info_observer_start")

#pragma comment(linker, "/export:info_orientation=metamod_org.info_orientation")

#pragma comment(linker, "/export:info_paintball=metamod_org.info_paintball")

#pragma comment(linker, "/export:info_particles=metamod_org.info_particles")

#pragma comment(linker, "/export:info_physics=metamod_org.info_physics")

#pragma comment(linker, "/export:info_pitworm=metamod_org.info_pitworm")

#pragma comment(linker, "/export:info_pitworm_steam_lock=metamod_org.info_pitworm_steam_lock")

#pragma comment(linker, "/export:info_player_allies=metamod_org.info_player_allies")

#pragma comment(linker, "/export:info_player_american=metamod_org.info_player_american")

#pragma comment(linker, "/export:info_player_attacker=metamod_org.info_player_attacker")

#pragma comment(linker, "/export:info_player_axis=metamod_org.info_player_axis")

#pragma comment(linker, "/export:info_player_blue=metamod_org.info_player_blue")

#pragma comment(linker, "/export:info_player_british=metamod_org.info_player_british")

#pragma comment(linker, "/export:info_player_coop=metamod_org.info_player_coop")

#pragma comment(linker, "/export:info_player_deadstart=metamod_org.info_player_deadstart")

#pragma comment(linker, "/export:info_player_deathmatch=metamod_org.info_player_deathmatch")

#pragma comment(linker, "/export:info_player_deathmatch_reverse=metamod_org.info_player_deathmatch_reverse")

#pragma comment(linker, "/export:info_player_defender=metamod_org.info_player_defender")

#pragma comment(linker, "/export:info_player_dm2=metamod_org.info_player_dm2")

#pragma comment(linker, "/export:info_player_equip=metamod_org.info_player_equip")

#pragma comment(linker, "/export:info_player_goauld=metamod_org.info_player_goauld")

#pragma comment(linker, "/export:info_player_jail=metamod_org.info_player_jail")

#pragma comment(linker, "/export:info_player_judge=metamod_org.info_player_judge")

#pragma comment(linker, "/export:info_player_knight=metamod_org.info_player_knight")

#pragma comment(linker, "/export:info_player_marine=metamod_org.info_player_marine")

#pragma comment(linker, "/export:info_player_nva_reenforcement=metamod_org.info_player_nva_reenforcement")

#pragma comment(linker, "/export:info_player_observer=metamod_org.info_player_observer")

#pragma comment(linker, "/export:info_player_perp=metamod_org.info_player_perp")

#pragma comment(linker, "/export:info_player_pirate=metamod_org.info_player_pirate")

#pragma comment(linker, "/export:info_player_red=metamod_org.info_player_red")

#pragma comment(linker, "/export:info_player_respawn=metamod_org.info_player_respawn")

#pragma comment(linker, "/export:info_player_slayer=metamod_org.info_player_slayer")

#pragma comment(linker, "/export:info_player_spectator=metamod_org.info_player_spectator")

#pragma comment(linker, "/export:info_player_start=metamod_org.info_player_start")

#pragma comment(linker, "/export:info_player_start_prox=metamod_org.info_player_start_prox")

#pragma comment(linker, "/export:info_player_start_reverse=metamod_org.info_player_start_reverse")

#pragma comment(linker, "/export:info_player_team1=metamod_org.info_player_team1")

#pragma comment(linker, "/export:info_player_team2=metamod_org.info_player_team2")

#pragma comment(linker, "/export:info_player_team_at=metamod_org.info_player_team_at")

#pragma comment(linker, "/export:info_player_team_bt=metamod_org.info_player_team_bt")

#pragma comment(linker, "/export:info_player_team_ce=metamod_org.info_player_team_ce")

#pragma comment(linker, "/export:info_player_team_cm=metamod_org.info_player_team_cm")

#pragma comment(linker, "/export:info_player_team_gf=metamod_org.info_player_team_gf")

#pragma comment(linker, "/export:info_player_team_iw=metamod_org.info_player_team_iw")

#pragma comment(linker, "/export:info_player_team_s=metamod_org.info_player_team_s")

#pragma comment(linker, "/export:info_player_team_sm=metamod_org.info_player_team_sm")

#pragma comment(linker, "/export:info_player_team_st=metamod_org.info_player_team_st")

#pragma comment(linker, "/export:info_player_team_we=metamod_org.info_player_team_we")

#pragma comment(linker, "/export:info_player_teamspawn=metamod_org.info_player_teamspawn")

#pragma comment(linker, "/export:info_player_torri=metamod_org.info_player_torri")

#pragma comment(linker, "/export:info_player_unas=metamod_org.info_player_unas")

#pragma comment(linker, "/export:info_player_usmc_reenforcement=metamod_org.info_player_usmc_reenforcement")

#pragma comment(linker, "/export:info_player_vampire=metamod_org.info_player_vampire")

#pragma comment(linker, "/export:info_player_viking=metamod_org.info_player_viking")

#pragma comment(linker, "/export:info_playerstart_blue=metamod_org.info_playerstart_blue")

#pragma comment(linker, "/export:info_playerstart_red=metamod_org.info_playerstart_red")

#pragma comment(linker, "/export:info_pvk=metamod_org.info_pvk")

#pragma comment(linker, "/export:info_radar_block=metamod_org.info_radar_block")

#pragma comment(linker, "/export:info_rescue_monster=metamod_org.info_rescue_monster")

#pragma comment(linker, "/export:info_rescue_point=metamod_org.info_rescue_point")

#pragma comment(linker, "/export:info_reset=metamod_org.info_reset")

#pragma comment(linker, "/export:info_robot_return=metamod_org.info_robot_return")

#pragma comment(linker, "/export:info_robot_start=metamod_org.info_robot_start")

#pragma comment(linker, "/export:info_roundx_spawn=metamod_org.info_roundx_spawn")

#pragma comment(linker, "/export:info_russian_start=metamod_org.info_russian_start")

#pragma comment(linker, "/export:info_sapin=metamod_org.info_sapin")

#pragma comment(linker, "/export:info_scientist=metamod_org.info_scientist")

#pragma comment(linker, "/export:info_scientist_dead=metamod_org.info_scientist_dead")

#pragma comment(linker, "/export:info_scientist_start=metamod_org.info_scientist_start")

#pragma comment(linker, "/export:info_semi_null=metamod_org.info_semi_null")

#pragma comment(linker, "/export:info_sidetect=metamod_org.info_sidetect")

#pragma comment(linker, "/export:info_spawn_container=metamod_org.info_spawn_container")

#pragma comment(linker, "/export:info_spectate=metamod_org.info_spectate")

#pragma comment(linker, "/export:info_sprite=metamod_org.info_sprite")

#pragma comment(linker, "/export:info_stadium=metamod_org.info_stadium")

#pragma comment(linker, "/export:info_status=metamod_org.info_status")

#pragma comment(linker, "/export:info_swat_start=metamod_org.info_swat_start")

#pragma comment(linker, "/export:info_target=metamod_org.info_target")

#pragma comment(linker, "/export:info_team=metamod_org.info_team")

#pragma comment(linker, "/export:info_team1_corner0=metamod_org.info_team1_corner0")

#pragma comment(linker, "/export:info_team1_corner1=metamod_org.info_team1_corner1")

#pragma comment(linker, "/export:info_team1_corner_player0=metamod_org.info_team1_corner_player0")

#pragma comment(linker, "/export:info_team1_corner_player1=metamod_org.info_team1_corner_player1")

#pragma comment(linker, "/export:info_team1_goalkick0=metamod_org.info_team1_goalkick0")

#pragma comment(linker, "/export:info_team1_goalkick1=metamod_org.info_team1_goalkick1")

#pragma comment(linker, "/export:info_team1_penalty_spot=metamod_org.info_team1_penalty_spot")

#pragma comment(linker, "/export:info_team1_player1=metamod_org.info_team1_player1")

#pragma comment(linker, "/export:info_team1_player10=metamod_org.info_team1_player10")

#pragma comment(linker, "/export:info_team1_player11=metamod_org.info_team1_player11")

#pragma comment(linker, "/export:info_team1_player2=metamod_org.info_team1_player2")

#pragma comment(linker, "/export:info_team1_player3=metamod_org.info_team1_player3")

#pragma comment(linker, "/export:info_team1_player4=metamod_org.info_team1_player4")

#pragma comment(linker, "/export:info_team1_player5=metamod_org.info_team1_player5")

#pragma comment(linker, "/export:info_team1_player6=metamod_org.info_team1_player6")

#pragma comment(linker, "/export:info_team1_player7=metamod_org.info_team1_player7")

#pragma comment(linker, "/export:info_team1_player8=metamod_org.info_team1_player8")

#pragma comment(linker, "/export:info_team1_player9=metamod_org.info_team1_player9")

#pragma comment(linker, "/export:info_team2_corner0=metamod_org.info_team2_corner0")

#pragma comment(linker, "/export:info_team2_corner1=metamod_org.info_team2_corner1")

#pragma comment(linker, "/export:info_team2_corner_player0=metamod_org.info_team2_corner_player0")

#pragma comment(linker, "/export:info_team2_corner_player1=metamod_org.info_team2_corner_player1")

#pragma comment(linker, "/export:info_team2_goalkick0=metamod_org.info_team2_goalkick0")

#pragma comment(linker, "/export:info_team2_goalkick1=metamod_org.info_team2_goalkick1")

#pragma comment(linker, "/export:info_team2_penalty_spot=metamod_org.info_team2_penalty_spot")

#pragma comment(linker, "/export:info_team2_player1=metamod_org.info_team2_player1")

#pragma comment(linker, "/export:info_team2_player10=metamod_org.info_team2_player10")

#pragma comment(linker, "/export:info_team2_player11=metamod_org.info_team2_player11")

#pragma comment(linker, "/export:info_team2_player2=metamod_org.info_team2_player2")

#pragma comment(linker, "/export:info_team2_player3=metamod_org.info_team2_player3")

#pragma comment(linker, "/export:info_team2_player4=metamod_org.info_team2_player4")

#pragma comment(linker, "/export:info_team2_player5=metamod_org.info_team2_player5")

#pragma comment(linker, "/export:info_team2_player6=metamod_org.info_team2_player6")

#pragma comment(linker, "/export:info_team2_player7=metamod_org.info_team2_player7")

#pragma comment(linker, "/export:info_team2_player8=metamod_org.info_team2_player8")

#pragma comment(linker, "/export:info_team2_player9=metamod_org.info_team2_player9")

#pragma comment(linker, "/export:info_team_base=metamod_org.info_team_base")

#pragma comment(linker, "/export:info_team_ronin=metamod_org.info_team_ronin")

#pragma comment(linker, "/export:info_team_scavenger=metamod_org.info_team_scavenger")

#pragma comment(linker, "/export:info_team_start=metamod_org.info_team_start")

#pragma comment(linker, "/export:info_team_usmc=metamod_org.info_team_usmc")

#pragma comment(linker, "/export:info_teamplaydetect=metamod_org.info_teamplaydetect")

#pragma comment(linker, "/export:info_teamspawn=metamod_org.info_teamspawn")

#pragma comment(linker, "/export:info_teleport_destination=metamod_org.info_teleport_destination")

#pragma comment(linker, "/export:info_texlights=metamod_org.info_texlights")

#pragma comment(linker, "/export:info_tf_teamcheck=metamod_org.info_tf_teamcheck")

#pragma comment(linker, "/export:info_tf_teamset=metamod_org.info_tf_teamset")

#pragma comment(linker, "/export:info_tfdetect=metamod_org.info_tfdetect")

#pragma comment(linker, "/export:info_tfgoal=metamod_org.info_tfgoal")

#pragma comment(linker, "/export:info_tfgoal_timer=metamod_org.info_tfgoal_timer")

#pragma comment(linker, "/export:info_throw_in=metamod_org.info_throw_in")

#pragma comment(linker, "/export:info_transistor=metamod_org.info_transistor")

#pragma comment(linker, "/export:info_transport_node=metamod_org.info_transport_node")

#pragma comment(linker, "/export:info_tt_gameplay=metamod_org.info_tt_gameplay")

#pragma comment(linker, "/export:info_upko_start=metamod_org.info_upko_start")

#pragma comment(linker, "/export:info_usa_start=metamod_org.info_usa_start")

#pragma comment(linker, "/export:info_vgui_start=metamod_org.info_vgui_start")

#pragma comment(linker, "/export:info_vip_start=metamod_org.info_vip_start")

#pragma comment(linker, "/export:info_wanteddetect=metamod_org.info_wanteddetect")

#pragma comment(linker, "/export:info_waypoint=metamod_org.info_waypoint")

#pragma comment(linker, "/export:info_ww_teamcheck=metamod_org.info_ww_teamcheck")

#pragma comment(linker, "/export:info_ww_teamset=metamod_org.info_ww_teamset")

#pragma comment(linker, "/export:info_wwdetect=metamod_org.info_wwdetect")

#pragma comment(linker, "/export:info_wwgoal=metamod_org.info_wwgoal")

#pragma comment(linker, "/export:info_wwgoal_timer=metamod_org.info_wwgoal_timer")

#pragma comment(linker, "/export:info_zone=metamod_org.info_zone")

#pragma comment(linker, "/export:info_zone_caisse=metamod_org.info_zone_caisse")

#pragma comment(linker, "/export:infodecal=metamod_org.infodecal")

#pragma comment(linker, "/export:inout_register=metamod_org.inout_register")

#pragma comment(linker, "/export:item_NVG=metamod_org.item_NVG")

#pragma comment(linker, "/export:item_PowerShield=metamod_org.item_PowerShield")

#pragma comment(linker, "/export:item_acme=metamod_org.item_acme")

#pragma comment(linker, "/export:item_airtank=metamod_org.item_airtank")

#pragma comment(linker, "/export:item_ammo=metamod_org.item_ammo")

#pragma comment(linker, "/export:item_ammoicon=metamod_org.item_ammoicon")

#pragma comment(linker, "/export:item_ammopack=metamod_org.item_ammopack")

#pragma comment(linker, "/export:item_antidote=metamod_org.item_antidote")

#pragma comment(linker, "/export:item_antidotee=metamod_org.item_antidotee")

#pragma comment(linker, "/export:item_antigrav=metamod_org.item_antigrav")

#pragma comment(linker, "/export:item_armor=metamod_org.item_armor")

#pragma comment(linker, "/export:item_armor1=metamod_org.item_armor1")

#pragma comment(linker, "/export:item_armor2=metamod_org.item_armor2")

#pragma comment(linker, "/export:item_armor3=metamod_org.item_armor3")

#pragma comment(linker, "/export:item_armorInv=metamod_org.item_armorInv")

#pragma comment(linker, "/export:item_armour=metamod_org.item_armour")

#pragma comment(linker, "/export:item_artifact_envirosuit=metamod_org.item_artifact_envirosuit")

#pragma comment(linker, "/export:item_artifact_invisibility=metamod_org.item_artifact_invisibility")

#pragma comment(linker, "/export:item_artifact_invulnerability=metamod_org.item_artifact_invulnerability")

#pragma comment(linker, "/export:item_artifact_super_damage=metamod_org.item_artifact_super_damage")

#pragma comment(linker, "/export:item_assaultsuit=metamod_org.item_assaultsuit")

#pragma comment(linker, "/export:item_atde_object=metamod_org.item_atde_object")

#pragma comment(linker, "/export:item_autodoc=metamod_org.item_autodoc")

#pragma comment(linker, "/export:item_backpack=metamod_org.item_backpack")

#pragma comment(linker, "/export:item_badge=metamod_org.item_badge")

#pragma comment(linker, "/export:item_bag1=metamod_org.item_bag1")

#pragma comment(linker, "/export:item_bag2=metamod_org.item_bag2")

#pragma comment(linker, "/export:item_banana=metamod_org.item_banana")

#pragma comment(linker, "/export:item_bandage=metamod_org.item_bandage")

#pragma comment(linker, "/export:item_bandolier=metamod_org.item_bandolier")

#pragma comment(linker, "/export:item_baril=metamod_org.item_baril")

#pragma comment(linker, "/export:item_baril_bleu=metamod_org.item_baril_bleu")

#pragma comment(linker, "/export:item_baril_rouge=metamod_org.item_baril_rouge")

#pragma comment(linker, "/export:item_battery=metamod_org.item_battery")

#pragma comment(linker, "/export:item_beans=metamod_org.item_beans")

#pragma comment(linker, "/export:item_body=metamod_org.item_body")

#pragma comment(linker, "/export:item_bonustime=metamod_org.item_bonustime")

#pragma comment(linker, "/export:item_bonustime2=metamod_org.item_bonustime2")

#pragma comment(linker, "/export:item_bonustime3=metamod_org.item_bonustime3")

#pragma comment(linker, "/export:item_book_team1=metamod_org.item_book_team1")

#pragma comment(linker, "/export:item_book_team2=metamod_org.item_book_team2")

#pragma comment(linker, "/export:item_bottle=metamod_org.item_bottle")

#pragma comment(linker, "/export:item_briefcase=metamod_org.item_briefcase")

#pragma comment(linker, "/export:item_c4=metamod_org.item_c4")

#pragma comment(linker, "/export:item_cactus=metamod_org.item_cactus")

#pragma comment(linker, "/export:item_caisse_arme=metamod_org.item_caisse_arme")

#pragma comment(linker, "/export:item_caisse_mega=metamod_org.item_caisse_mega")

#pragma comment(linker, "/export:item_caisse_outil=metamod_org.item_caisse_outil")

#pragma comment(linker, "/export:item_caisse_vie=metamod_org.item_caisse_vie")

#pragma comment(linker, "/export:item_canteen=metamod_org.item_canteen")

#pragma comment(linker, "/export:item_capkey=metamod_org.item_capkey")

#pragma comment(linker, "/export:item_cash=metamod_org.item_cash")

#pragma comment(linker, "/export:item_catalyst=metamod_org.item_catalyst")

#pragma comment(linker, "/export:item_cells=metamod_org.item_cells")

#pragma comment(linker, "/export:item_chainmail=metamod_org.item_chainmail")

#pragma comment(linker, "/export:item_chicken=metamod_org.item_chicken")

#pragma comment(linker, "/export:item_claymore=metamod_org.item_claymore")

#pragma comment(linker, "/export:item_cloak=metamod_org.item_cloak")

#pragma comment(linker, "/export:item_cloaker=metamod_org.item_cloaker")

#pragma comment(linker, "/export:item_concussion=metamod_org.item_concussion")

#pragma comment(linker, "/export:item_corpse=metamod_org.item_corpse")

#pragma comment(linker, "/export:item_ctf_flag=metamod_org.item_ctf_flag")

#pragma comment(linker, "/export:item_ctfaccelerator=metamod_org.item_ctfaccelerator")

#pragma comment(linker, "/export:item_ctfbackpack=metamod_org.item_ctfbackpack")

#pragma comment(linker, "/export:item_ctfbase=metamod_org.item_ctfbase")

#pragma comment(linker, "/export:item_ctfflag=metamod_org.item_ctfflag")

#pragma comment(linker, "/export:item_ctflongjump=metamod_org.item_ctflongjump")

#pragma comment(linker, "/export:item_ctfportablehev=metamod_org.item_ctfportablehev")

#pragma comment(linker, "/export:item_ctfregeneration=metamod_org.item_ctfregeneration")

#pragma comment(linker, "/export:item_dbldamage=metamod_org.item_dbldamage")

#pragma comment(linker, "/export:item_dish=metamod_org.item_dish")

#pragma comment(linker, "/export:item_docbag=metamod_org.item_docbag")

#pragma comment(linker, "/export:item_document=metamod_org.item_document")

#pragma comment(linker, "/export:item_dragonball=metamod_org.item_dragonball")

#pragma comment(linker, "/export:item_dyno=metamod_org.item_dyno")

#pragma comment(linker, "/export:item_dyno1=metamod_org.item_dyno1")

#pragma comment(linker, "/export:item_elixer=metamod_org.item_elixer")

#pragma comment(linker, "/export:item_elixir=metamod_org.item_elixir")

#pragma comment(linker, "/export:item_energy=metamod_org.item_energy")

#pragma comment(linker, "/export:item_flag=metamod_org.item_flag")

#pragma comment(linker, "/export:item_flag1=metamod_org.item_flag1")

#pragma comment(linker, "/export:item_flag2=metamod_org.item_flag2")

#pragma comment(linker, "/export:item_flag_atde=metamod_org.item_flag_atde")

#pragma comment(linker, "/export:item_flag_blue=metamod_org.item_flag_blue")

#pragma comment(linker, "/export:item_flag_center=metamod_org.item_flag_center")

#pragma comment(linker, "/export:item_flag_cf=metamod_org.item_flag_cf")

#pragma comment(linker, "/export:item_flag_ctf=metamod_org.item_flag_ctf")

#pragma comment(linker, "/export:item_flag_red=metamod_org.item_flag_red")

#pragma comment(linker, "/export:item_flag_slayer=metamod_org.item_flag_slayer")

#pragma comment(linker, "/export:item_flag_team1=metamod_org.item_flag_team1")

#pragma comment(linker, "/export:item_flag_team2=metamod_org.item_flag_team2")

#pragma comment(linker, "/export:item_flag_vampire=metamod_org.item_flag_vampire")

#pragma comment(linker, "/export:item_flashbang=metamod_org.item_flashbang")

#pragma comment(linker, "/export:item_flashlight=metamod_org.item_flashlight")

#pragma comment(linker, "/export:item_food=metamod_org.item_food")

#pragma comment(linker, "/export:item_frag=metamod_org.item_frag")

#pragma comment(linker, "/export:item_fruit=metamod_org.item_fruit")

#pragma comment(linker, "/export:item_gascan=metamod_org.item_gascan")

#pragma comment(linker, "/export:item_generic=metamod_org.item_generic")

#pragma comment(linker, "/export:item_genericammo=metamod_org.item_genericammo")

#pragma comment(linker, "/export:item_glass=metamod_org.item_glass")

#pragma comment(linker, "/export:item_grappin=metamod_org.item_grappin")

#pragma comment(linker, "/export:item_head=metamod_org.item_head")

#pragma comment(linker, "/export:item_health=metamod_org.item_health")

#pragma comment(linker, "/export:item_healthkit=metamod_org.item_healthkit")

#pragma comment(linker, "/export:item_heavyarmor=metamod_org.item_heavyarmor")

#pragma comment(linker, "/export:item_herbs=metamod_org.item_herbs")

#pragma comment(linker, "/export:item_highjump=metamod_org.item_highjump")

#pragma comment(linker, "/export:item_holster=metamod_org.item_holster")

#pragma comment(linker, "/export:item_infjetpack=metamod_org.item_infjetpack")

#pragma comment(linker, "/export:item_invincibility=metamod_org.item_invincibility")

#pragma comment(linker, "/export:item_invisibility=metamod_org.item_invisibility")

#pragma comment(linker, "/export:item_irnvg=metamod_org.item_irnvg")

#pragma comment(linker, "/export:item_jetpack=metamod_org.item_jetpack")

#pragma comment(linker, "/export:item_kevlar=metamod_org.item_kevlar")

#pragma comment(linker, "/export:item_knife=metamod_org.item_knife")

#pragma comment(linker, "/export:item_laser=metamod_org.item_laser")

#pragma comment(linker, "/export:item_leather=metamod_org.item_leather")

#pragma comment(linker, "/export:item_lgboiler=metamod_org.item_lgboiler")

#pragma comment(linker, "/export:item_longjump=metamod_org.item_longjump")

#pragma comment(linker, "/export:item_mask=metamod_org.item_mask")

#pragma comment(linker, "/export:item_medboiler=metamod_org.item_medboiler")

#pragma comment(linker, "/export:item_megavirus=metamod_org.item_megavirus")

#pragma comment(linker, "/export:item_metal=metamod_org.item_metal")

#pragma comment(linker, "/export:item_mine=metamod_org.item_mine")

#pragma comment(linker, "/export:item_money=metamod_org.item_money")

#pragma comment(linker, "/export:item_moneycase=metamod_org.item_moneycase")

#pragma comment(linker, "/export:item_newspaper=metamod_org.item_newspaper")

#pragma comment(linker, "/export:item_nightvision=metamod_org.item_nightvision")

#pragma comment(linker, "/export:item_nuclearbomb=metamod_org.item_nuclearbomb")

#pragma comment(linker, "/export:item_nuclearbombbutton=metamod_org.item_nuclearbombbutton")

#pragma comment(linker, "/export:item_nuclearbombtimer=metamod_org.item_nuclearbombtimer")

#pragma comment(linker, "/export:item_nvg=metamod_org.item_nvg")

#pragma comment(linker, "/export:item_objective=metamod_org.item_objective")

#pragma comment(linker, "/export:item_papers=metamod_org.item_papers")

#pragma comment(linker, "/export:item_parachute=metamod_org.item_parachute")

#pragma comment(linker, "/export:item_pickaxe=metamod_org.item_pickaxe")

#pragma comment(linker, "/export:item_platemail=metamod_org.item_platemail")

#pragma comment(linker, "/export:item_portableHEV=metamod_org.item_portableHEV")

#pragma comment(linker, "/export:item_portableHealthkit=metamod_org.item_portableHealthkit")

#pragma comment(linker, "/export:item_powerarmor=metamod_org.item_powerarmor")

#pragma comment(linker, "/export:item_powerup=metamod_org.item_powerup")

#pragma comment(linker, "/export:item_pt=metamod_org.item_pt")

#pragma comment(linker, "/export:item_quad=metamod_org.item_quad")

#pragma comment(linker, "/export:item_radio=metamod_org.item_radio")

#pragma comment(linker, "/export:item_random=metamod_org.item_random")

#pragma comment(linker, "/export:item_regeneration=metamod_org.item_regeneration")

#pragma comment(linker, "/export:item_resource=metamod_org.item_resource")

#pragma comment(linker, "/export:item_rockets=metamod_org.item_rockets")

#pragma comment(linker, "/export:item_scope=metamod_org.item_scope")

#pragma comment(linker, "/export:item_security=metamod_org.item_security")

#pragma comment(linker, "/export:item_sensubeanbag=metamod_org.item_sensubeanbag")

#pragma comment(linker, "/export:item_shells=metamod_org.item_shells")

#pragma comment(linker, "/export:item_shovel=metamod_org.item_shovel")

#pragma comment(linker, "/export:item_silencer=metamod_org.item_silencer")

#pragma comment(linker, "/export:item_silvercase=metamod_org.item_silvercase")

#pragma comment(linker, "/export:item_smboiler=metamod_org.item_smboiler")

#pragma comment(linker, "/export:item_sodacan=metamod_org.item_sodacan")

#pragma comment(linker, "/export:item_speedburst=metamod_org.item_speedburst")

#pragma comment(linker, "/export:item_spikes=metamod_org.item_spikes")

#pragma comment(linker, "/export:item_stealth=metamod_org.item_stealth")

#pragma comment(linker, "/export:item_steerribs=metamod_org.item_steerribs")

#pragma comment(linker, "/export:item_steerskull=metamod_org.item_steerskull")

#pragma comment(linker, "/export:item_stg24=metamod_org.item_stg24")

#pragma comment(linker, "/export:item_suit=metamod_org.item_suit")

#pragma comment(linker, "/export:item_swarm_flag=metamod_org.item_swarm_flag")

#pragma comment(linker, "/export:item_tag=metamod_org.item_tag")

#pragma comment(linker, "/export:item_telegram=metamod_org.item_telegram")

#pragma comment(linker, "/export:item_telegraphkey=metamod_org.item_telegraphkey")

#pragma comment(linker, "/export:item_teleport=metamod_org.item_teleport")

#pragma comment(linker, "/export:item_tfgoal=metamod_org.item_tfgoal")

#pragma comment(linker, "/export:item_thighpack=metamod_org.item_thighpack")

#pragma comment(linker, "/export:item_tombe_bleu=metamod_org.item_tombe_bleu")

#pragma comment(linker, "/export:item_tombe_rouge=metamod_org.item_tombe_rouge")

#pragma comment(linker, "/export:item_treasurechest=metamod_org.item_treasurechest")

#pragma comment(linker, "/export:item_upgradevest=metamod_org.item_upgradevest")

#pragma comment(linker, "/export:item_vengeance=metamod_org.item_vengeance")

#pragma comment(linker, "/export:item_vest=metamod_org.item_vest")

#pragma comment(linker, "/export:item_wagonwheel=metamod_org.item_wagonwheel")

#pragma comment(linker, "/export:item_weapon=metamod_org.item_weapon")

#pragma comment(linker, "/export:item_wheelside=metamod_org.item_wheelside")

#pragma comment(linker, "/export:item_wwgoal=metamod_org.item_wwgoal")

#pragma comment(linker, "/export:jail_execute=metamod_org.jail_execute")

#pragma comment(linker, "/export:jail_team_master=metamod_org.jail_team_master")

#pragma comment(linker, "/export:jailer=metamod_org.jailer")

#pragma comment(linker, "/export:javelin=metamod_org.javelin")

#pragma comment(linker, "/export:judge=metamod_org.judge")

#pragma comment(linker, "/export:jumppad_sign=metamod_org.jumppad_sign")

#pragma comment(linker, "/export:kamehameha=metamod_org.kamehameha")

#pragma comment(linker, "/export:kb_fireworklauncher=metamod_org.kb_fireworklauncher")

#pragma comment(linker, "/export:killerrat=metamod_org.killerrat")

#pragma comment(linker, "/export:knife=metamod_org.knife")

#pragma comment(linker, "/export:knife_bolt=metamod_org.knife_bolt")

#pragma comment(linker, "/export:knife_throw=metamod_org.knife_throw")

#pragma comment(linker, "/export:kotm_crown=metamod_org.kotm_crown")

#pragma comment(linker, "/export:kotm_hill=metamod_org.kotm_hill")

#pragma comment(linker, "/export:kwSpikeProjectile=metamod_org.kwSpikeProjectile")

#pragma comment(linker, "/export:lance_proj=metamod_org.lance_proj")

#pragma comment(linker, "/export:laser_aimer=metamod_org.laser_aimer")

#pragma comment(linker, "/export:laser_dot=metamod_org.laser_dot")

#pragma comment(linker, "/export:laser_spot=metamod_org.laser_spot")

#pragma comment(linker, "/export:laserbolt=metamod_org.laserbolt")

#pragma comment(linker, "/export:law_rocket=metamod_org.law_rocket")

#pragma comment(linker, "/export:lc_init_ent=metamod_org.lc_init_ent")

#pragma comment(linker, "/export:lc_respawner=metamod_org.lc_respawner")

#pragma comment(linker, "/export:lc_spawner=metamod_org.lc_spawner")

#pragma comment(linker, "/export:lcs_spawner=metamod_org.lcs_spawner")

#pragma comment(linker, "/export:lflamme_fire=metamod_org.lflamme_fire")

#pragma comment(linker, "/export:lgtng_ball=metamod_org.lgtng_ball")

#pragma comment(linker, "/export:lifesoul=metamod_org.lifesoul")

#pragma comment(linker, "/export:light=metamod_org.light")

#pragma comment(linker, "/export:light_environment=metamod_org.light_environment")

#pragma comment(linker, "/export:light_glow=metamod_org.light_glow")

#pragma comment(linker, "/export:light_spot=metamod_org.light_spot")

#pragma comment(linker, "/export:lightfader=metamod_org.lightfader")

#pragma comment(linker, "/export:load_wpt=metamod_org.load_wpt")

#pragma comment(linker, "/export:locus_alias=metamod_org.locus_alias")

#pragma comment(linker, "/export:locus_beam=metamod_org.locus_beam")

#pragma comment(linker, "/export:locus_variable=metamod_org.locus_variable")

#pragma comment(linker, "/export:m203grenade=metamod_org.m203grenade")

#pragma comment(linker, "/export:m61_grenade=metamod_org.m61_grenade")

#pragma comment(linker, "/export:m72_rocket=metamod_org.m72_rocket")

#pragma comment(linker, "/export:magicattack=metamod_org.magicattack")

#pragma comment(linker, "/export:maintainer_ent=metamod_org.maintainer_ent")

#pragma comment(linker, "/export:mapClassName=metamod_org.mapClassName")

#pragma comment(linker, "/export:mapobject_asiancar=metamod_org.mapobject_asiancar")

#pragma comment(linker, "/export:mapobject_bluecar=metamod_org.mapobject_bluecar")

#pragma comment(linker, "/export:mapobject_copcar=metamod_org.mapobject_copcar")

#pragma comment(linker, "/export:mapobject_jaguar=metamod_org.mapobject_jaguar")

#pragma comment(linker, "/export:mapobject_npc_bum=metamod_org.mapobject_npc_bum")

#pragma comment(linker, "/export:mapobject_npc_bum1=metamod_org.mapobject_npc_bum1")

#pragma comment(linker, "/export:mapobject_npc_bum2=metamod_org.mapobject_npc_bum2")

#pragma comment(linker, "/export:mapobject_npc_bum3=metamod_org.mapobject_npc_bum3")

#pragma comment(linker, "/export:mapobject_npc_crow=metamod_org.mapobject_npc_crow")

#pragma comment(linker, "/export:mapobject_npc_slavebot=metamod_org.mapobject_npc_slavebot")

#pragma comment(linker, "/export:mapobject_redcar=metamod_org.mapobject_redcar")

#pragma comment(linker, "/export:mapobject_zeppelin=metamod_org.mapobject_zeppelin")

#pragma comment(linker, "/export:marker=metamod_org.marker")

#pragma comment(linker, "/export:marker_flag=metamod_org.marker_flag")

#pragma comment(linker, "/export:master_key=metamod_org.master_key")

#pragma comment(linker, "/export:master_living=metamod_org.master_living")

#pragma comment(linker, "/export:master_object_home=metamod_org.master_object_home")

#pragma comment(linker, "/export:master_period=metamod_org.master_period")

#pragma comment(linker, "/export:master_player=metamod_org.master_player")

#pragma comment(linker, "/export:master_relay=metamod_org.master_relay")

#pragma comment(linker, "/export:master_round_active=metamod_org.master_round_active")

#pragma comment(linker, "/export:master_round_start=metamod_org.master_round_start")

#pragma comment(linker, "/export:master_secret=metamod_org.master_secret")

#pragma comment(linker, "/export:master_state=metamod_org.master_state")

#pragma comment(linker, "/export:master_team=metamod_org.master_team")

#pragma comment(linker, "/export:master_tech=metamod_org.master_tech")

#pragma comment(linker, "/export:mastertoggle=metamod_org.mastertoggle")

#pragma comment(linker, "/export:mazo=metamod_org.mazo")

#pragma comment(linker, "/export:mazoold=metamod_org.mazoold")

#pragma comment(linker, "/export:medal=metamod_org.medal")

#pragma comment(linker, "/export:medevac=metamod_org.medevac")

#pragma comment(linker, "/export:medivac=metamod_org.medivac")

#pragma comment(linker, "/export:meteor_god=metamod_org.meteor_god")

#pragma comment(linker, "/export:meteor_target=metamod_org.meteor_target")

#pragma comment(linker, "/export:mi_capture_zone=metamod_org.mi_capture_zone")

#pragma comment(linker, "/export:mi_fail_objective=metamod_org.mi_fail_objective")

#pragma comment(linker, "/export:mi_func_fog=metamod_org.mi_func_fog")

#pragma comment(linker, "/export:mi_grass=metamod_org.mi_grass")

#pragma comment(linker, "/export:mi_model=metamod_org.mi_model")

#pragma comment(linker, "/export:mi_model_names=metamod_org.mi_model_names")

#pragma comment(linker, "/export:mi_model_static=metamod_org.mi_model_static")

#pragma comment(linker, "/export:mi_obj_icon=metamod_org.mi_obj_icon")

#pragma comment(linker, "/export:mi_obj_switch=metamod_org.mi_obj_switch")

#pragma comment(linker, "/export:mi_objective_attack=metamod_org.mi_objective_attack")

#pragma comment(linker, "/export:mi_objective_bomb=metamod_org.mi_objective_bomb")

#pragma comment(linker, "/export:mi_objective_defend=metamod_org.mi_objective_defend")

#pragma comment(linker, "/export:mi_objective_destruct=metamod_org.mi_objective_destruct")

#pragma comment(linker, "/export:mi_objective_extraction=metamod_org.mi_objective_extraction")

#pragma comment(linker, "/export:mi_objective_hosrescue=metamod_org.mi_objective_hosrescue")

#pragma comment(linker, "/export:mi_objective_hostage=metamod_org.mi_objective_hostage")

#pragma comment(linker, "/export:mi_objective_observation=metamod_org.mi_objective_observation")

#pragma comment(linker, "/export:mi_objective_other=metamod_org.mi_objective_other")

#pragma comment(linker, "/export:mi_objective_repair=metamod_org.mi_objective_repair")

#pragma comment(linker, "/export:mi_objective_team1=metamod_org.mi_objective_team1")

#pragma comment(linker, "/export:mi_objective_team2=metamod_org.mi_objective_team2")

#pragma comment(linker, "/export:mi_respawn=metamod_org.mi_respawn")

#pragma comment(linker, "/export:mi_set_objective=metamod_org.mi_set_objective")

#pragma comment(linker, "/export:mi_set_respawn=metamod_org.mi_set_respawn")

#pragma comment(linker, "/export:mi_set_timer=metamod_org.mi_set_timer")

#pragma comment(linker, "/export:mi_spawn_zone=metamod_org.mi_spawn_zone")

#pragma comment(linker, "/export:mi_team_damage=metamod_org.mi_team_damage")

#pragma comment(linker, "/export:mi_team_names=metamod_org.mi_team_names")

#pragma comment(linker, "/export:mi_team_push=metamod_org.mi_team_push")

#pragma comment(linker, "/export:mi_team_skins=metamod_org.mi_team_skins")

#pragma comment(linker, "/export:mi_timer=metamod_org.mi_timer")

#pragma comment(linker, "/export:mi_trigger_weather=metamod_org.mi_trigger_weather")

#pragma comment(linker, "/export:mi_weather=metamod_org.mi_weather")

#pragma comment(linker, "/export:mini_grunt=metamod_org.mini_grunt")

#pragma comment(linker, "/export:mini_rocket=metamod_org.mini_rocket")

#pragma comment(linker, "/export:mission_modifier=metamod_org.mission_modifier")

#pragma comment(linker, "/export:misterx=metamod_org.misterx")

#pragma comment(linker, "/export:mode_relay=metamod_org.mode_relay")

#pragma comment(linker, "/export:model_entity=metamod_org.model_entity")

#pragma comment(linker, "/export:molotov=metamod_org.molotov")

#pragma comment(linker, "/export:momentary_door=metamod_org.momentary_door")

#pragma comment(linker, "/export:momentary_jail_door=metamod_org.momentary_jail_door")

#pragma comment(linker, "/export:momentary_rot_button=metamod_org.momentary_rot_button")

#pragma comment(linker, "/export:monster_ShockTrooper_dead=metamod_org.monster_ShockTrooper_dead")

#pragma comment(linker, "/export:monster_a10=metamod_org.monster_a10")

#pragma comment(linker, "/export:monster_adrian=metamod_org.monster_adrian")

#pragma comment(linker, "/export:monster_adrian_dead=metamod_org.monster_adrian_dead")

#pragma comment(linker, "/export:monster_alarm=metamod_org.monster_alarm")

#pragma comment(linker, "/export:monster_alien_babyvoltigore=metamod_org.monster_alien_babyvoltigore")

#pragma comment(linker, "/export:monster_alien_controller=metamod_org.monster_alien_controller")

#pragma comment(linker, "/export:monster_alien_grunt=metamod_org.monster_alien_grunt")

#pragma comment(linker, "/export:monster_alien_panther=metamod_org.monster_alien_panther")

#pragma comment(linker, "/export:monster_alien_slave=metamod_org.monster_alien_slave")

#pragma comment(linker, "/export:monster_alien_slave_dead=metamod_org.monster_alien_slave_dead")

#pragma comment(linker, "/export:monster_alien_voltigore=metamod_org.monster_alien_voltigore")

#pragma comment(linker, "/export:monster_allied_barney=metamod_org.monster_allied_barney")

#pragma comment(linker, "/export:monster_allied_grunt=metamod_org.monster_allied_grunt")

#pragma comment(linker, "/export:monster_alliedgrunt_dead=metamod_org.monster_alliedgrunt_dead")

#pragma comment(linker, "/export:monster_annie=metamod_org.monster_annie")

#pragma comment(linker, "/export:monster_annie_dead=metamod_org.monster_annie_dead")

#pragma comment(linker, "/export:monster_apache=metamod_org.monster_apache")

#pragma comment(linker, "/export:monster_archer=metamod_org.monster_archer")

#pragma comment(linker, "/export:monster_assassin_repel=metamod_org.monster_assassin_repel")

#pragma comment(linker, "/export:monster_assassin_target=metamod_org.monster_assassin_target")

#pragma comment(linker, "/export:monster_axis_grunt=metamod_org.monster_axis_grunt")

#pragma comment(linker, "/export:monster_axisgrunt_dead=metamod_org.monster_axisgrunt_dead")

#pragma comment(linker, "/export:monster_babycrab=metamod_org.monster_babycrab")

#pragma comment(linker, "/export:monster_babygarg=metamod_org.monster_babygarg")

#pragma comment(linker, "/export:monster_balllightning=metamod_org.monster_balllightning")

#pragma comment(linker, "/export:monster_barnacle=metamod_org.monster_barnacle")

#pragma comment(linker, "/export:monster_barney=metamod_org.monster_barney")

#pragma comment(linker, "/export:monster_barney_dead=metamod_org.monster_barney_dead")

#pragma comment(linker, "/export:monster_barniel=metamod_org.monster_barniel")

#pragma comment(linker, "/export:monster_barniel_dead=metamod_org.monster_barniel_dead")

#pragma comment(linker, "/export:monster_bbturret=metamod_org.monster_bbturret")

#pragma comment(linker, "/export:monster_beak=metamod_org.monster_beak")

#pragma comment(linker, "/export:monster_bear=metamod_org.monster_bear")

#pragma comment(linker, "/export:monster_beartrap=metamod_org.monster_beartrap")

#pragma comment(linker, "/export:monster_bigminer=metamod_org.monster_bigminer")

#pragma comment(linker, "/export:monster_bigminer_dead=metamod_org.monster_bigminer_dead")

#pragma comment(linker, "/export:monster_bigmomma=metamod_org.monster_bigmomma")

#pragma comment(linker, "/export:monster_blkop_apache=metamod_org.monster_blkop_apache")

#pragma comment(linker, "/export:monster_blkop_ospray=metamod_org.monster_blkop_ospray")

#pragma comment(linker, "/export:monster_blkop_osprey=metamod_org.monster_blkop_osprey")

#pragma comment(linker, "/export:monster_bloater=metamod_org.monster_bloater")

#pragma comment(linker, "/export:monster_bodypart=metamod_org.monster_bodypart")

#pragma comment(linker, "/export:monster_bomb=metamod_org.monster_bomb")

#pragma comment(linker, "/export:monster_buffalo=metamod_org.monster_buffalo")

#pragma comment(linker, "/export:monster_bullchicken=metamod_org.monster_bullchicken")

#pragma comment(linker, "/export:monster_bullsquid=metamod_org.monster_bullsquid")

#pragma comment(linker, "/export:monster_burnmine=metamod_org.monster_burnmine")

#pragma comment(linker, "/export:monster_c4=metamod_org.monster_c4")

#pragma comment(linker, "/export:monster_camera=metamod_org.monster_camera")

#pragma comment(linker, "/export:monster_cat=metamod_org.monster_cat")

#pragma comment(linker, "/export:monster_chicken=metamod_org.monster_chicken")

#pragma comment(linker, "/export:monster_chumtoad=metamod_org.monster_chumtoad")

#pragma comment(linker, "/export:monster_cine2_crispen=metamod_org.monster_cine2_crispen")

#pragma comment(linker, "/export:monster_cine2_dave=metamod_org.monster_cine2_dave")

#pragma comment(linker, "/export:monster_cine2_hvyweapons=metamod_org.monster_cine2_hvyweapons")

#pragma comment(linker, "/export:monster_cine2_masala=metamod_org.monster_cine2_masala")

#pragma comment(linker, "/export:monster_cine2_nagatow=metamod_org.monster_cine2_nagatow")

#pragma comment(linker, "/export:monster_cine2_scientist=metamod_org.monster_cine2_scientist")

#pragma comment(linker, "/export:monster_cine2_slave=metamod_org.monster_cine2_slave")

#pragma comment(linker, "/export:monster_cine2_tiedcolonel=metamod_org.monster_cine2_tiedcolonel")

#pragma comment(linker, "/export:monster_cine2_townmex=metamod_org.monster_cine2_townmex")

#pragma comment(linker, "/export:monster_cine2_wtowna=metamod_org.monster_cine2_wtowna")

#pragma comment(linker, "/export:monster_cine2_wtownb=metamod_org.monster_cine2_wtownb")

#pragma comment(linker, "/export:monster_cine3_annie=metamod_org.monster_cine3_annie")

#pragma comment(linker, "/export:monster_cine3_barney=metamod_org.monster_cine3_barney")

#pragma comment(linker, "/export:monster_cine3_crispen=metamod_org.monster_cine3_crispen")

#pragma comment(linker, "/export:monster_cine3_dave=metamod_org.monster_cine3_dave")

#pragma comment(linker, "/export:monster_cine3_hoss=metamod_org.monster_cine3_hoss")

#pragma comment(linker, "/export:monster_cine3_masala=metamod_org.monster_cine3_masala")

#pragma comment(linker, "/export:monster_cine3_nagatow=metamod_org.monster_cine3_nagatow")

#pragma comment(linker, "/export:monster_cine3_scientist=metamod_org.monster_cine3_scientist")

#pragma comment(linker, "/export:monster_cine3_tiedcolonel=metamod_org.monster_cine3_tiedcolonel")

#pragma comment(linker, "/export:monster_cine3_townmex=metamod_org.monster_cine3_townmex")

#pragma comment(linker, "/export:monster_cine3_wtowna=metamod_org.monster_cine3_wtowna")

#pragma comment(linker, "/export:monster_cine3_wtownb=metamod_org.monster_cine3_wtownb")

#pragma comment(linker, "/export:monster_cine_annie=metamod_org.monster_cine_annie")

#pragma comment(linker, "/export:monster_cine_barney=metamod_org.monster_cine_barney")

#pragma comment(linker, "/export:monster_cine_crispen=metamod_org.monster_cine_crispen")

#pragma comment(linker, "/export:monster_cine_dave=metamod_org.monster_cine_dave")

#pragma comment(linker, "/export:monster_cine_hoss=metamod_org.monster_cine_hoss")

#pragma comment(linker, "/export:monster_cine_masala=metamod_org.monster_cine_masala")

#pragma comment(linker, "/export:monster_cine_nagatow=metamod_org.monster_cine_nagatow")

#pragma comment(linker, "/export:monster_cine_panther=metamod_org.monster_cine_panther")

#pragma comment(linker, "/export:monster_cine_scientist=metamod_org.monster_cine_scientist")

#pragma comment(linker, "/export:monster_cine_tiedcolonel=metamod_org.monster_cine_tiedcolonel")

#pragma comment(linker, "/export:monster_cine_townmex=metamod_org.monster_cine_townmex")

#pragma comment(linker, "/export:monster_cine_wtowna=metamod_org.monster_cine_wtowna")

#pragma comment(linker, "/export:monster_cine_wtownb=metamod_org.monster_cine_wtownb")

#pragma comment(linker, "/export:monster_civilian=metamod_org.monster_civilian")

#pragma comment(linker, "/export:monster_civilian_dead=metamod_org.monster_civilian_dead")

#pragma comment(linker, "/export:monster_cleansuit_scientist=metamod_org.monster_cleansuit_scientist")

#pragma comment(linker, "/export:monster_cleansuit_scientist_dead=metamod_org.monster_cleansuit_scientist_dead")

#pragma comment(linker, "/export:monster_cockroach=metamod_org.monster_cockroach")

#pragma comment(linker, "/export:monster_colonel=metamod_org.monster_colonel")

#pragma comment(linker, "/export:monster_colonel_dead=metamod_org.monster_colonel_dead")

#pragma comment(linker, "/export:monster_cow=metamod_org.monster_cow")

#pragma comment(linker, "/export:monster_cowboy=metamod_org.monster_cowboy")

#pragma comment(linker, "/export:monster_cowboy_dead=metamod_org.monster_cowboy_dead")

#pragma comment(linker, "/export:monster_cricket=metamod_org.monster_cricket")

#pragma comment(linker, "/export:monster_crispen=metamod_org.monster_crispen")

#pragma comment(linker, "/export:monster_crispen_dead=metamod_org.monster_crispen_dead")

#pragma comment(linker, "/export:monster_critter=metamod_org.monster_critter")

#pragma comment(linker, "/export:monster_darttrap=metamod_org.monster_darttrap")

#pragma comment(linker, "/export:monster_dave=metamod_org.monster_dave")

#pragma comment(linker, "/export:monster_dave_dead=metamod_org.monster_dave_dead")

#pragma comment(linker, "/export:monster_demo=metamod_org.monster_demo")

#pragma comment(linker, "/export:monster_dog=metamod_org.monster_dog")

#pragma comment(linker, "/export:monster_dragon=metamod_org.monster_dragon")

#pragma comment(linker, "/export:monster_dragonfly=metamod_org.monster_dragonfly")

#pragma comment(linker, "/export:monster_drillsergeant=metamod_org.monster_drillsergeant")

#pragma comment(linker, "/export:monster_eagle=metamod_org.monster_eagle")

#pragma comment(linker, "/export:monster_eagle_flock=metamod_org.monster_eagle_flock")

#pragma comment(linker, "/export:monster_endboss=metamod_org.monster_endboss")

#pragma comment(linker, "/export:monster_exp_alien_slave=metamod_org.monster_exp_alien_slave")

#pragma comment(linker, "/export:monster_fakemedkit=metamod_org.monster_fakemedkit")

#pragma comment(linker, "/export:monster_fgrunt_repel=metamod_org.monster_fgrunt_repel")

#pragma comment(linker, "/export:monster_flag1=metamod_org.monster_flag1")

#pragma comment(linker, "/export:monster_flag2=metamod_org.monster_flag2")

#pragma comment(linker, "/export:monster_flag3=metamod_org.monster_flag3")

#pragma comment(linker, "/export:monster_flag4=metamod_org.monster_flag4")

#pragma comment(linker, "/export:monster_flashlight=metamod_org.monster_flashlight")

#pragma comment(linker, "/export:monster_flyer=metamod_org.monster_flyer")

#pragma comment(linker, "/export:monster_flyer_flock=metamod_org.monster_flyer_flock")

#pragma comment(linker, "/export:monster_furniture=metamod_org.monster_furniture")

#pragma comment(linker, "/export:monster_garbage=metamod_org.monster_garbage")

#pragma comment(linker, "/export:monster_gargantua=metamod_org.monster_gargantua")

#pragma comment(linker, "/export:monster_gator=metamod_org.monster_gator")

#pragma comment(linker, "/export:monster_generic=metamod_org.monster_generic")

#pragma comment(linker, "/export:monster_generic_dead=metamod_org.monster_generic_dead")

#pragma comment(linker, "/export:monster_geneworm=metamod_org.monster_geneworm")

#pragma comment(linker, "/export:monster_giantplant=metamod_org.monster_giantplant")

#pragma comment(linker, "/export:monster_gman=metamod_org.monster_gman")

#pragma comment(linker, "/export:monster_goat=metamod_org.monster_goat")

#pragma comment(linker, "/export:monster_goblin=metamod_org.monster_goblin")

#pragma comment(linker, "/export:monster_gonome=metamod_org.monster_gonome")

#pragma comment(linker, "/export:monster_gonome_dead=metamod_org.monster_gonome_dead")

#pragma comment(linker, "/export:monster_gordon=metamod_org.monster_gordon")

#pragma comment(linker, "/export:monster_gordon_dead=metamod_org.monster_gordon_dead")

#pragma comment(linker, "/export:monster_gps=metamod_org.monster_gps")

#pragma comment(linker, "/export:monster_grunt_ally_medic_dead=metamod_org.monster_grunt_ally_medic_dead")

#pragma comment(linker, "/export:monster_grunt_ally_repel=metamod_org.monster_grunt_ally_repel")

#pragma comment(linker, "/export:monster_grunt_ally_torch_dead=metamod_org.monster_grunt_ally_torch_dead")

#pragma comment(linker, "/export:monster_grunt_repel=metamod_org.monster_grunt_repel")

#pragma comment(linker, "/export:monster_gunner_friendly=metamod_org.monster_gunner_friendly")

#pragma comment(linker, "/export:monster_hatchetfish=metamod_org.monster_hatchetfish")

#pragma comment(linker, "/export:monster_headcrab=metamod_org.monster_headcrab")

#pragma comment(linker, "/export:monster_helicopter=metamod_org.monster_helicopter")

#pragma comment(linker, "/export:monster_hevbarn=metamod_org.monster_hevbarn")

#pragma comment(linker, "/export:monster_hevbarn_dead=metamod_org.monster_hevbarn_dead")

#pragma comment(linker, "/export:monster_hevsuit_dead=metamod_org.monster_hevsuit_dead")

#pragma comment(linker, "/export:monster_hfgrunt_dead=metamod_org.monster_hfgrunt_dead")

#pragma comment(linker, "/export:monster_hgrunt=metamod_org.monster_hgrunt")

#pragma comment(linker, "/export:monster_hgrunt_dead=metamod_org.monster_hgrunt_dead")

#pragma comment(linker, "/export:monster_hgrunt_shotgun=metamod_org.monster_hgrunt_shotgun")

#pragma comment(linker, "/export:monster_hiveback=metamod_org.monster_hiveback")

#pragma comment(linker, "/export:monster_horse=metamod_org.monster_horse")

#pragma comment(linker, "/export:monster_hoss=metamod_org.monster_hoss")

#pragma comment(linker, "/export:monster_hoss_dead=metamod_org.monster_hoss_dead")

#pragma comment(linker, "/export:monster_hostage=metamod_org.monster_hostage")

#pragma comment(linker, "/export:monster_hostage_dead=metamod_org.monster_hostage_dead")

#pragma comment(linker, "/export:monster_houndeye=metamod_org.monster_houndeye")

#pragma comment(linker, "/export:monster_houndeye_dead=metamod_org.monster_houndeye_dead")

#pragma comment(linker, "/export:monster_human_assassin=metamod_org.monster_human_assassin")

#pragma comment(linker, "/export:monster_human_bandit=metamod_org.monster_human_bandit")

#pragma comment(linker, "/export:monster_human_chopper=metamod_org.monster_human_chopper")

#pragma comment(linker, "/export:monster_human_demoman=metamod_org.monster_human_demoman")

#pragma comment(linker, "/export:monster_human_friendly_grunt=metamod_org.monster_human_friendly_grunt")

#pragma comment(linker, "/export:monster_human_grunt=metamod_org.monster_human_grunt")

#pragma comment(linker, "/export:monster_human_grunt_ally=metamod_org.monster_human_grunt_ally")

#pragma comment(linker, "/export:monster_human_grunt_ally_dead=metamod_org.monster_human_grunt_ally_dead")

#pragma comment(linker, "/export:monster_human_gunman=metamod_org.monster_human_gunman")

#pragma comment(linker, "/export:monster_human_medic_ally=metamod_org.monster_human_medic_ally")

#pragma comment(linker, "/export:monster_human_medic_ally_dead=metamod_org.monster_human_medic_ally_dead")

#pragma comment(linker, "/export:monster_human_scientist=metamod_org.monster_human_scientist")

#pragma comment(linker, "/export:monster_human_spforce=metamod_org.monster_human_spforce")

#pragma comment(linker, "/export:monster_human_terror=metamod_org.monster_human_terror")

#pragma comment(linker, "/export:monster_human_torch_ally=metamod_org.monster_human_torch_ally")

#pragma comment(linker, "/export:monster_human_torch_ally_dead=metamod_org.monster_human_torch_ally_dead")

#pragma comment(linker, "/export:monster_human_unarmed=metamod_org.monster_human_unarmed")

#pragma comment(linker, "/export:monster_hwgrunt=metamod_org.monster_hwgrunt")

#pragma comment(linker, "/export:monster_hwgrunt_repel=metamod_org.monster_hwgrunt_repel")

#pragma comment(linker, "/export:monster_ichthyosaur=metamod_org.monster_ichthyosaur")

#pragma comment(linker, "/export:monster_implanted=metamod_org.monster_implanted")

#pragma comment(linker, "/export:monster_kaiewi=metamod_org.monster_kaiewi")

#pragma comment(linker, "/export:monster_kaiewi_dead=metamod_org.monster_kaiewi_dead")

#pragma comment(linker, "/export:monster_kate=metamod_org.monster_kate")

#pragma comment(linker, "/export:monster_kate_dead=metamod_org.monster_kate_dead")

#pragma comment(linker, "/export:monster_kid=metamod_org.monster_kid")

#pragma comment(linker, "/export:monster_killerbabycrab=metamod_org.monster_killerbabycrab")

#pragma comment(linker, "/export:monster_largescorpion=metamod_org.monster_largescorpion")

#pragma comment(linker, "/export:monster_larve=metamod_org.monster_larve")

#pragma comment(linker, "/export:monster_leech=metamod_org.monster_leech")

#pragma comment(linker, "/export:monster_llama=metamod_org.monster_llama")

#pragma comment(linker, "/export:monster_lrocket=metamod_org.monster_lrocket")

#pragma comment(linker, "/export:monster_m2=metamod_org.monster_m2")

#pragma comment(linker, "/export:monster_male_assassin=metamod_org.monster_male_assassin")

#pragma comment(linker, "/export:monster_manta=metamod_org.monster_manta")

#pragma comment(linker, "/export:monster_masala=metamod_org.monster_masala")

#pragma comment(linker, "/export:monster_masala_dead=metamod_org.monster_masala_dead")

#pragma comment(linker, "/export:monster_massassin_dead=metamod_org.monster_massassin_dead")

#pragma comment(linker, "/export:monster_medic_ally_repel=metamod_org.monster_medic_ally_repel")

#pragma comment(linker, "/export:monster_mexbandit=metamod_org.monster_mexbandit")

#pragma comment(linker, "/export:monster_mexbandit_dead=metamod_org.monster_mexbandit_dead")

#pragma comment(linker, "/export:monster_microraptor=metamod_org.monster_microraptor")

#pragma comment(linker, "/export:monster_mine=metamod_org.monster_mine")

#pragma comment(linker, "/export:monster_miniturret=metamod_org.monster_miniturret")

#pragma comment(linker, "/export:monster_missle=metamod_org.monster_missle")

#pragma comment(linker, "/export:monster_monkey=metamod_org.monster_monkey")

#pragma comment(linker, "/export:monster_mortar=metamod_org.monster_mortar")

#pragma comment(linker, "/export:monster_morter=metamod_org.monster_morter")

#pragma comment(linker, "/export:monster_mouton=metamod_org.monster_mouton")

#pragma comment(linker, "/export:monster_myself=metamod_org.monster_myself")

#pragma comment(linker, "/export:monster_myself_dead=metamod_org.monster_myself_dead")

#pragma comment(linker, "/export:monster_nagatow=metamod_org.monster_nagatow")

#pragma comment(linker, "/export:monster_nagatow_dead=metamod_org.monster_nagatow_dead")

#pragma comment(linker, "/export:monster_nihilanth=metamod_org.monster_nihilanth")

#pragma comment(linker, "/export:monster_op4loader=metamod_org.monster_op4loader")

#pragma comment(linker, "/export:monster_osprey=metamod_org.monster_osprey")

#pragma comment(linker, "/export:monster_otis=metamod_org.monster_otis")

#pragma comment(linker, "/export:monster_otis_dead=metamod_org.monster_otis_dead")

#pragma comment(linker, "/export:monster_ourano=metamod_org.monster_ourano")

#pragma comment(linker, "/export:monster_parachute=metamod_org.monster_parachute")

#pragma comment(linker, "/export:monster_parrot=metamod_org.monster_parrot")

#pragma comment(linker, "/export:monster_penguin=metamod_org.monster_penguin")

#pragma comment(linker, "/export:monster_penta=metamod_org.monster_penta")

#pragma comment(linker, "/export:monster_pig=metamod_org.monster_pig")

#pragma comment(linker, "/export:monster_pilot=metamod_org.monster_pilot")

#pragma comment(linker, "/export:monster_pipebomb=metamod_org.monster_pipebomb")

#pragma comment(linker, "/export:monster_pitdrone=metamod_org.monster_pitdrone")

#pragma comment(linker, "/export:monster_pitworm=metamod_org.monster_pitworm")

#pragma comment(linker, "/export:monster_pitworm_up=metamod_org.monster_pitworm_up")

#pragma comment(linker, "/export:monster_player=metamod_org.monster_player")

#pragma comment(linker, "/export:monster_poison=metamod_org.monster_poison")

#pragma comment(linker, "/export:monster_powderkeg=metamod_org.monster_powderkeg")

#pragma comment(linker, "/export:monster_prisoner=metamod_org.monster_prisoner")

#pragma comment(linker, "/export:monster_prop_apache=metamod_org.monster_prop_apache")

#pragma comment(linker, "/export:monster_proximity=metamod_org.monster_proximity")

#pragma comment(linker, "/export:monster_puma=metamod_org.monster_puma")

#pragma comment(linker, "/export:monster_ramone=metamod_org.monster_ramone")

#pragma comment(linker, "/export:monster_ramone_repel=metamod_org.monster_ramone_repel")

#pragma comment(linker, "/export:monster_raptor=metamod_org.monster_raptor")

#pragma comment(linker, "/export:monster_rat=metamod_org.monster_rat")

#pragma comment(linker, "/export:monster_recruit=metamod_org.monster_recruit")

#pragma comment(linker, "/export:monster_replic=metamod_org.monster_replic")

#pragma comment(linker, "/export:monster_replicateur=metamod_org.monster_replicateur")

#pragma comment(linker, "/export:monster_replicator=metamod_org.monster_replicator")

#pragma comment(linker, "/export:monster_robogrunt=metamod_org.monster_robogrunt")

#pragma comment(linker, "/export:monster_robogrunt_dead=metamod_org.monster_robogrunt_dead")

#pragma comment(linker, "/export:monster_robogrunt_repel=metamod_org.monster_robogrunt_repel")

#pragma comment(linker, "/export:monster_robogruntrepel=metamod_org.monster_robogruntrepel")

#pragma comment(linker, "/export:monster_rustbattery=metamod_org.monster_rustbattery")

#pragma comment(linker, "/export:monster_rustbit=metamod_org.monster_rustbit")

#pragma comment(linker, "/export:monster_rustbit_friendly=metamod_org.monster_rustbit_friendly")

#pragma comment(linker, "/export:monster_rustflier=metamod_org.monster_rustflier")

#pragma comment(linker, "/export:monster_rustgunr=metamod_org.monster_rustgunr")

#pragma comment(linker, "/export:monster_sarge_allies=metamod_org.monster_sarge_allies")

#pragma comment(linker, "/export:monster_satchel=metamod_org.monster_satchel")

#pragma comment(linker, "/export:monster_scientist=metamod_org.monster_scientist")

#pragma comment(linker, "/export:monster_scientist_dead=metamod_org.monster_scientist_dead")

#pragma comment(linker, "/export:monster_scorpion=metamod_org.monster_scorpion")

#pragma comment(linker, "/export:monster_sentry=metamod_org.monster_sentry")

#pragma comment(linker, "/export:monster_sentry_mini=metamod_org.monster_sentry_mini")

#pragma comment(linker, "/export:monster_sentryx=metamod_org.monster_sentryx")

#pragma comment(linker, "/export:monster_sheep=metamod_org.monster_sheep")

#pragma comment(linker, "/export:monster_shockroach=metamod_org.monster_shockroach")

#pragma comment(linker, "/export:monster_shocktrooper=metamod_org.monster_shocktrooper")

#pragma comment(linker, "/export:monster_shocktrooper_repel=metamod_org.monster_shocktrooper_repel")

#pragma comment(linker, "/export:monster_shotgun=metamod_org.monster_shotgun")

#pragma comment(linker, "/export:monster_sitting_civilian=metamod_org.monster_sitting_civilian")

#pragma comment(linker, "/export:monster_sitting_cleansuit_scientist=metamod_org.monster_sitting_cleansuit_scientist")

#pragma comment(linker, "/export:monster_sitting_colonel=metamod_org.monster_sitting_colonel")

#pragma comment(linker, "/export:monster_sitting_crispen=metamod_org.monster_sitting_crispen")

#pragma comment(linker, "/export:monster_sitting_dave=metamod_org.monster_sitting_dave")

#pragma comment(linker, "/export:monster_sitting_masala=metamod_org.monster_sitting_masala")

#pragma comment(linker, "/export:monster_sitting_nagatow=metamod_org.monster_sitting_nagatow")

#pragma comment(linker, "/export:monster_sitting_scientist=metamod_org.monster_sitting_scientist")

#pragma comment(linker, "/export:monster_sitting_townmex=metamod_org.monster_sitting_townmex")

#pragma comment(linker, "/export:monster_sitting_twnwesta=metamod_org.monster_sitting_twnwesta")

#pragma comment(linker, "/export:monster_sitting_twnwestb=metamod_org.monster_sitting_twnwestb")

#pragma comment(linker, "/export:monster_sitting_villager=metamod_org.monster_sitting_villager")

#pragma comment(linker, "/export:monster_skeleton=metamod_org.monster_skeleton")

#pragma comment(linker, "/export:monster_skeleton_dead=metamod_org.monster_skeleton_dead")

#pragma comment(linker, "/export:monster_skelly=metamod_org.monster_skelly")

#pragma comment(linker, "/export:monster_skellydance=metamod_org.monster_skellydance")

#pragma comment(linker, "/export:monster_skull=metamod_org.monster_skull")

#pragma comment(linker, "/export:monster_skunk=metamod_org.monster_skunk")

#pragma comment(linker, "/export:monster_smallminer=metamod_org.monster_smallminer")

#pragma comment(linker, "/export:monster_smallminer_dead=metamod_org.monster_smallminer_dead")

#pragma comment(linker, "/export:monster_snake=metamod_org.monster_snake")

#pragma comment(linker, "/export:monster_snark=metamod_org.monster_snark")

#pragma comment(linker, "/export:monster_spforce_dead=metamod_org.monster_spforce_dead")

#pragma comment(linker, "/export:monster_spforce_repel=metamod_org.monster_spforce_repel")

#pragma comment(linker, "/export:monster_sphere=metamod_org.monster_sphere")

#pragma comment(linker, "/export:monster_spider=metamod_org.monster_spider")

#pragma comment(linker, "/export:monster_spiritdragon=metamod_org.monster_spiritdragon")

#pragma comment(linker, "/export:monster_spiritwiz=metamod_org.monster_spiritwiz")

#pragma comment(linker, "/export:monster_srocket=metamod_org.monster_srocket")

#pragma comment(linker, "/export:monster_super_snark=metamod_org.monster_super_snark")

#pragma comment(linker, "/export:monster_tac=metamod_org.monster_tac")

#pragma comment(linker, "/export:monster_tank=metamod_org.monster_tank")

#pragma comment(linker, "/export:monster_target=metamod_org.monster_target")

#pragma comment(linker, "/export:monster_targetrocket=metamod_org.monster_targetrocket")

#pragma comment(linker, "/export:monster_tentacle=metamod_org.monster_tentacle")

#pragma comment(linker, "/export:monster_tentaclemaw=metamod_org.monster_tentaclemaw")

#pragma comment(linker, "/export:monster_terror_dead=metamod_org.monster_terror_dead")

#pragma comment(linker, "/export:monster_terror_repel=metamod_org.monster_terror_repel")

#pragma comment(linker, "/export:monster_test=metamod_org.monster_test")

#pragma comment(linker, "/export:monster_thornbush=metamod_org.monster_thornbush")

#pragma comment(linker, "/export:monster_tied_colonel=metamod_org.monster_tied_colonel")

#pragma comment(linker, "/export:monster_torch_ally_repel=metamod_org.monster_torch_ally_repel")

#pragma comment(linker, "/export:monster_tornado=metamod_org.monster_tornado")

#pragma comment(linker, "/export:monster_townmex=metamod_org.monster_townmex")

#pragma comment(linker, "/export:monster_townmex_dead=metamod_org.monster_townmex_dead")

#pragma comment(linker, "/export:monster_trainingbot=metamod_org.monster_trainingbot")

#pragma comment(linker, "/export:monster_tripmine=metamod_org.monster_tripmine")

#pragma comment(linker, "/export:monster_troop=metamod_org.monster_troop")

#pragma comment(linker, "/export:monster_tube=metamod_org.monster_tube")

#pragma comment(linker, "/export:monster_tube_embryo=metamod_org.monster_tube_embryo")

#pragma comment(linker, "/export:monster_turret=metamod_org.monster_turret")

#pragma comment(linker, "/export:monster_turretbase=metamod_org.monster_turretbase")

#pragma comment(linker, "/export:monster_twnwesta=metamod_org.monster_twnwesta")

#pragma comment(linker, "/export:monster_twnwesta_dead=metamod_org.monster_twnwesta_dead")

#pragma comment(linker, "/export:monster_twnwestb=metamod_org.monster_twnwestb")

#pragma comment(linker, "/export:monster_twnwestb_dead=metamod_org.monster_twnwestb_dead")

#pragma comment(linker, "/export:monster_valve_turret=metamod_org.monster_valve_turret")

#pragma comment(linker, "/export:monster_villager=metamod_org.monster_villager")

#pragma comment(linker, "/export:monster_villager_dead=metamod_org.monster_villager_dead")

#pragma comment(linker, "/export:monster_vortigaunt=metamod_org.monster_vortigaunt")

#pragma comment(linker, "/export:monster_wizardclone=metamod_org.monster_wizardclone")

#pragma comment(linker, "/export:monster_wombat=metamod_org.monster_wombat")

#pragma comment(linker, "/export:monster_worker=metamod_org.monster_worker")

#pragma comment(linker, "/export:monster_worker_dead=metamod_org.monster_worker_dead")

#pragma comment(linker, "/export:monster_wwmine=metamod_org.monster_wwmine")

#pragma comment(linker, "/export:monster_xenome=metamod_org.monster_xenome")

#pragma comment(linker, "/export:monster_xenome_embryo=metamod_org.monster_xenome_embryo")

#pragma comment(linker, "/export:monster_zbarney=metamod_org.monster_zbarney")

#pragma comment(linker, "/export:monster_zombie=metamod_org.monster_zombie")

#pragma comment(linker, "/export:monster_zombie2=metamod_org.monster_zombie2")

#pragma comment(linker, "/export:monster_zombie_barney=metamod_org.monster_zombie_barney")

#pragma comment(linker, "/export:monster_zombie_soldier=metamod_org.monster_zombie_soldier")

#pragma comment(linker, "/export:monster_zombie_soldier_dead=metamod_org.monster_zombie_soldier_dead")

#pragma comment(linker, "/export:monstermaker=metamod_org.monstermaker")

#pragma comment(linker, "/export:monsterpoint=metamod_org.monsterpoint")

#pragma comment(linker, "/export:monsterpoint_backup=metamod_org.monsterpoint_backup")

#pragma comment(linker, "/export:mortar_shell=metamod_org.mortar_shell")

#pragma comment(linker, "/export:mortarshell=metamod_org.mortarshell")

#pragma comment(linker, "/export:motion_manager=metamod_org.motion_manager")

#pragma comment(linker, "/export:motion_thread=metamod_org.motion_thread")

#pragma comment(linker, "/export:movementchamber=metamod_org.movementchamber")

#pragma comment(linker, "/export:moving_camera=metamod_org.moving_camera")

#pragma comment(linker, "/export:multi_alias=metamod_org.multi_alias")

#pragma comment(linker, "/export:multi_gate_1=metamod_org.multi_gate_1")

#pragma comment(linker, "/export:multi_gate_10=metamod_org.multi_gate_10")

#pragma comment(linker, "/export:multi_gate_11=metamod_org.multi_gate_11")

#pragma comment(linker, "/export:multi_gate_12=metamod_org.multi_gate_12")

#pragma comment(linker, "/export:multi_gate_13=metamod_org.multi_gate_13")

#pragma comment(linker, "/export:multi_gate_14=metamod_org.multi_gate_14")

#pragma comment(linker, "/export:multi_gate_15=metamod_org.multi_gate_15")

#pragma comment(linker, "/export:multi_gate_16=metamod_org.multi_gate_16")

#pragma comment(linker, "/export:multi_gate_17=metamod_org.multi_gate_17")

#pragma comment(linker, "/export:multi_gate_18=metamod_org.multi_gate_18")

#pragma comment(linker, "/export:multi_gate_19=metamod_org.multi_gate_19")

#pragma comment(linker, "/export:multi_gate_2=metamod_org.multi_gate_2")

#pragma comment(linker, "/export:multi_gate_20=metamod_org.multi_gate_20")

#pragma comment(linker, "/export:multi_gate_21=metamod_org.multi_gate_21")

#pragma comment(linker, "/export:multi_gate_22=metamod_org.multi_gate_22")

#pragma comment(linker, "/export:multi_gate_23=metamod_org.multi_gate_23")

#pragma comment(linker, "/export:multi_gate_24=metamod_org.multi_gate_24")

#pragma comment(linker, "/export:multi_gate_25=metamod_org.multi_gate_25")

#pragma comment(linker, "/export:multi_gate_26=metamod_org.multi_gate_26")

#pragma comment(linker, "/export:multi_gate_27=metamod_org.multi_gate_27")

#pragma comment(linker, "/export:multi_gate_28=metamod_org.multi_gate_28")

#pragma comment(linker, "/export:multi_gate_29=metamod_org.multi_gate_29")

#pragma comment(linker, "/export:multi_gate_3=metamod_org.multi_gate_3")

#pragma comment(linker, "/export:multi_gate_30=metamod_org.multi_gate_30")

#pragma comment(linker, "/export:multi_gate_31=metamod_org.multi_gate_31")

#pragma comment(linker, "/export:multi_gate_32=metamod_org.multi_gate_32")

#pragma comment(linker, "/export:multi_gate_33=metamod_org.multi_gate_33")

#pragma comment(linker, "/export:multi_gate_34=metamod_org.multi_gate_34")

#pragma comment(linker, "/export:multi_gate_35=metamod_org.multi_gate_35")

#pragma comment(linker, "/export:multi_gate_36=metamod_org.multi_gate_36")

#pragma comment(linker, "/export:multi_gate_37=metamod_org.multi_gate_37")

#pragma comment(linker, "/export:multi_gate_38=metamod_org.multi_gate_38")

#pragma comment(linker, "/export:multi_gate_39=metamod_org.multi_gate_39")

#pragma comment(linker, "/export:multi_gate_4=metamod_org.multi_gate_4")

#pragma comment(linker, "/export:multi_gate_40=metamod_org.multi_gate_40")

#pragma comment(linker, "/export:multi_gate_41=metamod_org.multi_gate_41")

#pragma comment(linker, "/export:multi_gate_42=metamod_org.multi_gate_42")

#pragma comment(linker, "/export:multi_gate_43=metamod_org.multi_gate_43")

#pragma comment(linker, "/export:multi_gate_44=metamod_org.multi_gate_44")

#pragma comment(linker, "/export:multi_gate_45=metamod_org.multi_gate_45")

#pragma comment(linker, "/export:multi_gate_46=metamod_org.multi_gate_46")

#pragma comment(linker, "/export:multi_gate_47=metamod_org.multi_gate_47")

#pragma comment(linker, "/export:multi_gate_48=metamod_org.multi_gate_48")

#pragma comment(linker, "/export:multi_gate_49=metamod_org.multi_gate_49")

#pragma comment(linker, "/export:multi_gate_5=metamod_org.multi_gate_5")

#pragma comment(linker, "/export:multi_gate_6=metamod_org.multi_gate_6")

#pragma comment(linker, "/export:multi_gate_7=metamod_org.multi_gate_7")

#pragma comment(linker, "/export:multi_gate_8=metamod_org.multi_gate_8")

#pragma comment(linker, "/export:multi_gate_9=metamod_org.multi_gate_9")

#pragma comment(linker, "/export:multi_manager=metamod_org.multi_manager")

#pragma comment(linker, "/export:multi_watcher=metamod_org.multi_watcher")

#pragma comment(linker, "/export:multisource=metamod_org.multisource")

#pragma comment(linker, "/export:my_monster=metamod_org.my_monster")

#pragma comment(linker, "/export:nail=metamod_org.nail")

#pragma comment(linker, "/export:neutrinobeam=metamod_org.neutrinobeam")

#pragma comment(linker, "/export:nggrenade=metamod_org.nggrenade")

#pragma comment(linker, "/export:nihilanth_energy_ball=metamod_org.nihilanth_energy_ball")

#pragma comment(linker, "/export:node_viewer=metamod_org.node_viewer")

#pragma comment(linker, "/export:node_viewer_fly=metamod_org.node_viewer_fly")

#pragma comment(linker, "/export:node_viewer_human=metamod_org.node_viewer_human")

#pragma comment(linker, "/export:node_viewer_large=metamod_org.node_viewer_large")

#pragma comment(linker, "/export:npc=metamod_org.npc")

#pragma comment(linker, "/export:npc_skrunk=metamod_org.npc_skrunk")

#pragma comment(linker, "/export:nuclear_missile=metamod_org.nuclear_missile")

#pragma comment(linker, "/export:nuke=metamod_org.nuke")

#pragma comment(linker, "/export:nuke_rocket=metamod_org.nuke_rocket")

#pragma comment(linker, "/export:object=metamod_org.object")

#pragma comment(linker, "/export:object_beacon=metamod_org.object_beacon")

#pragma comment(linker, "/export:object_follow=metamod_org.object_follow")

#pragma comment(linker, "/export:object_maker=metamod_org.object_maker")

#pragma comment(linker, "/export:object_superchip=metamod_org.object_superchip")

#pragma comment(linker, "/export:offensechamber=metamod_org.offensechamber")

#pragma comment(linker, "/export:ol_bell=metamod_org.ol_bell")

#pragma comment(linker, "/export:ol_bluecapture=metamod_org.ol_bluecapture")

#pragma comment(linker, "/export:ol_blueflag=metamod_org.ol_blueflag")

#pragma comment(linker, "/export:ol_bottle=metamod_org.ol_bottle")

#pragma comment(linker, "/export:ol_ctf_blueteam=metamod_org.ol_ctf_blueteam")

#pragma comment(linker, "/export:ol_ctf_redteam=metamod_org.ol_ctf_redteam")

#pragma comment(linker, "/export:ol_furniture=metamod_org.ol_furniture")

#pragma comment(linker, "/export:ol_lantern=metamod_org.ol_lantern")

#pragma comment(linker, "/export:ol_redcapture=metamod_org.ol_redcapture")

#pragma comment(linker, "/export:ol_redflag=metamod_org.ol_redflag")

#pragma comment(linker, "/export:ol_spitoon=metamod_org.ol_spitoon")

#pragma comment(linker, "/export:old_rocket=metamod_org.old_rocket")

#pragma comment(linker, "/export:oldbot=metamod_org.oldbot")

#pragma comment(linker, "/export:op4mortar=metamod_org.op4mortar")

#pragma comment(linker, "/export:oz_logo=metamod_org.oz_logo")

#pragma comment(linker, "/export:oz_rune=metamod_org.oz_rune")

#pragma comment(linker, "/export:paintball=metamod_org.paintball")

#pragma comment(linker, "/export:palm_tree=metamod_org.palm_tree")

#pragma comment(linker, "/export:para_roundtimer=metamod_org.para_roundtimer")

#pragma comment(linker, "/export:particle=metamod_org.particle")

#pragma comment(linker, "/export:particle_shooter=metamod_org.particle_shooter")

#pragma comment(linker, "/export:particle_weatherfx=metamod_org.particle_weatherfx")

#pragma comment(linker, "/export:path_corner=metamod_org.path_corner")

#pragma comment(linker, "/export:path_monster=metamod_org.path_monster")

#pragma comment(linker, "/export:path_track=metamod_org.path_track")

#pragma comment(linker, "/export:pballblue=metamod_org.pballblue")

#pragma comment(linker, "/export:pballred=metamod_org.pballred")

#pragma comment(linker, "/export:pe_escapezone=metamod_org.pe_escapezone")

#pragma comment(linker, "/export:pe_light=metamod_org.pe_light")

#pragma comment(linker, "/export:pe_light_ref=metamod_org.pe_light_ref")

#pragma comment(linker, "/export:pe_object_case=metamod_org.pe_object_case")

#pragma comment(linker, "/export:pe_object_htool=metamod_org.pe_object_htool")

#pragma comment(linker, "/export:pe_objectclip=metamod_org.pe_objectclip")

#pragma comment(linker, "/export:pe_radar_mark=metamod_org.pe_radar_mark")

#pragma comment(linker, "/export:pe_rain=metamod_org.pe_rain")

#pragma comment(linker, "/export:pe_spawn_corps=metamod_org.pe_spawn_corps")

#pragma comment(linker, "/export:pe_spawn_syndicate=metamod_org.pe_spawn_syndicate")

#pragma comment(linker, "/export:pe_terminal=metamod_org.pe_terminal")

#pragma comment(linker, "/export:phase_pulse=metamod_org.phase_pulse")

#pragma comment(linker, "/export:phasegate=metamod_org.phasegate")

#pragma comment(linker, "/export:pickup_drive_agrunt=metamod_org.pickup_drive_agrunt")

#pragma comment(linker, "/export:pickup_drive_apache=metamod_org.pickup_drive_apache")

#pragma comment(linker, "/export:pickup_drive_assassin=metamod_org.pickup_drive_assassin")

#pragma comment(linker, "/export:pickup_drive_bm=metamod_org.pickup_drive_bm")

#pragma comment(linker, "/export:pickup_drive_bullsquid=metamod_org.pickup_drive_bullsquid")

#pragma comment(linker, "/export:pickup_drive_controller=metamod_org.pickup_drive_controller")

#pragma comment(linker, "/export:pickup_drive_garg=metamod_org.pickup_drive_garg")

#pragma comment(linker, "/export:pickup_drive_houndeye=metamod_org.pickup_drive_houndeye")

#pragma comment(linker, "/export:pickup_drive_icky=metamod_org.pickup_drive_icky")

#pragma comment(linker, "/export:pickup_drive_panth=metamod_org.pickup_drive_panth")

#pragma comment(linker, "/export:pickup_drive_slave=metamod_org.pickup_drive_slave")

#pragma comment(linker, "/export:pickup_drive_turret=metamod_org.pickup_drive_turret")

#pragma comment(linker, "/export:pineapple=metamod_org.pineapple")

#pragma comment(linker, "/export:pipe_bomb=metamod_org.pipe_bomb")

#pragma comment(linker, "/export:pipebomb=metamod_org.pipebomb")

#pragma comment(linker, "/export:pitdronespike=metamod_org.pitdronespike")

#pragma comment(linker, "/export:pitworm_gib=metamod_org.pitworm_gib")

#pragma comment(linker, "/export:pitworm_gibshooter=metamod_org.pitworm_gibshooter")

#pragma comment(linker, "/export:plasma=metamod_org.plasma")

#pragma comment(linker, "/export:plasma2=metamod_org.plasma2")

#pragma comment(linker, "/export:plasma_ball=metamod_org.plasma_ball")

#pragma comment(linker, "/export:player=metamod_org.player")

#pragma comment(linker, "/export:player_beartrapstrip=metamod_org.player_beartrapstrip")

#pragma comment(linker, "/export:player_corpse=metamod_org.player_corpse")

#pragma comment(linker, "/export:player_flame=metamod_org.player_flame")

#pragma comment(linker, "/export:player_freeze=metamod_org.player_freeze")

#pragma comment(linker, "/export:player_giveitems=metamod_org.player_giveitems")

#pragma comment(linker, "/export:player_glasses=metamod_org.player_glasses")

#pragma comment(linker, "/export:player_helmet=metamod_org.player_helmet")

#pragma comment(linker, "/export:player_loadsaved=metamod_org.player_loadsaved")

#pragma comment(linker, "/export:player_respawn_zone=metamod_org.player_respawn_zone")

#pragma comment(linker, "/export:player_roach=metamod_org.player_roach")

#pragma comment(linker, "/export:player_speaker=metamod_org.player_speaker")

#pragma comment(linker, "/export:player_togglehud=metamod_org.player_togglehud")

#pragma comment(linker, "/export:player_weaponship=metamod_org.player_weaponship")

#pragma comment(linker, "/export:player_weaponstrip=metamod_org.player_weaponstrip")

#pragma comment(linker, "/export:playerhornet=metamod_org.playerhornet")

#pragma comment(linker, "/export:point_win=metamod_org.point_win")

#pragma comment(linker, "/export:poison_injected=metamod_org.poison_injected")

#pragma comment(linker, "/export:potatoc=metamod_org.potatoc")

#pragma comment(linker, "/export:power_bag=metamod_org.power_bag")

#pragma comment(linker, "/export:power_ballbag=metamod_org.power_ballbag")

#pragma comment(linker, "/export:power_coco=metamod_org.power_coco")

#pragma comment(linker, "/export:power_gloves=metamod_org.power_gloves")

#pragma comment(linker, "/export:power_pogo=metamod_org.power_pogo")

#pragma comment(linker, "/export:power_shield=metamod_org.power_shield")

#pragma comment(linker, "/export:power_shoes=metamod_org.power_shoes")

#pragma comment(linker, "/export:powerstruggle=metamod_org.powerstruggle")

#pragma comment(linker, "/export:powerup_candy=metamod_org.powerup_candy")

#pragma comment(linker, "/export:proj_bird=metamod_org.proj_bird")

#pragma comment(linker, "/export:proj_blaster=metamod_org.proj_blaster")

#pragma comment(linker, "/export:proj_bursatchel=metamod_org.proj_bursatchel")

#pragma comment(linker, "/export:proj_cocklebur=metamod_org.proj_cocklebur")

#pragma comment(linker, "/export:proj_comet=metamod_org.proj_comet")

#pragma comment(linker, "/export:proj_doublemagicmissle=metamod_org.proj_doublemagicmissle")

#pragma comment(linker, "/export:proj_dragonfire=metamod_org.proj_dragonfire")

#pragma comment(linker, "/export:proj_earthquakesatchel=metamod_org.proj_earthquakesatchel")

#pragma comment(linker, "/export:proj_fireball=metamod_org.proj_fireball")

#pragma comment(linker, "/export:proj_firesatchel=metamod_org.proj_firesatchel")

#pragma comment(linker, "/export:proj_firespiral=metamod_org.proj_firespiral")

#pragma comment(linker, "/export:proj_fissure=metamod_org.proj_fissure")

#pragma comment(linker, "/export:proj_flame=metamod_org.proj_flame")

#pragma comment(linker, "/export:proj_flyingskull=metamod_org.proj_flyingskull")

#pragma comment(linker, "/export:proj_healhurtsatchel=metamod_org.proj_healhurtsatchel")

#pragma comment(linker, "/export:proj_icepoke=metamod_org.proj_icepoke")

#pragma comment(linker, "/export:proj_iceshard=metamod_org.proj_iceshard")

#pragma comment(linker, "/export:proj_lightningcloud=metamod_org.proj_lightningcloud")

#pragma comment(linker, "/export:proj_lightningsatchel=metamod_org.proj_lightningsatchel")

#pragma comment(linker, "/export:proj_magicmissle=metamod_org.proj_magicmissle")

#pragma comment(linker, "/export:proj_meteor=metamod_org.proj_meteor")

#pragma comment(linker, "/export:proj_mindmissle=metamod_org.proj_mindmissle")

#pragma comment(linker, "/export:proj_missile=metamod_org.proj_missile")

#pragma comment(linker, "/export:proj_poisonsatchel=metamod_org.proj_poisonsatchel")

#pragma comment(linker, "/export:proj_rollingstone=metamod_org.proj_rollingstone")

#pragma comment(linker, "/export:proj_sporepod=metamod_org.proj_sporepod")

#pragma comment(linker, "/export:proj_stone=metamod_org.proj_stone")

#pragma comment(linker, "/export:proj_suctionsatchel=metamod_org.proj_suctionsatchel")

#pragma comment(linker, "/export:proj_tcrystal=metamod_org.proj_tcrystal")

#pragma comment(linker, "/export:proj_throwingbone=metamod_org.proj_throwingbone")

#pragma comment(linker, "/export:proj_toothsatchel=metamod_org.proj_toothsatchel")

#pragma comment(linker, "/export:proj_whirlwind=metamod_org.proj_whirlwind")

#pragma comment(linker, "/export:proj_wyvern=metamod_org.proj_wyvern")

#pragma comment(linker, "/export:promagcurse=metamod_org.promagcurse")

#pragma comment(linker, "/export:pshield_det=metamod_org.pshield_det")

#pragma comment(linker, "/export:pt_bomb_zone=metamod_org.pt_bomb_zone")

#pragma comment(linker, "/export:pt_campaign_end=metamod_org.pt_campaign_end")

#pragma comment(linker, "/export:pt_change_attribute=metamod_org.pt_change_attribute")

#pragma comment(linker, "/export:pt_control_area=metamod_org.pt_control_area")

#pragma comment(linker, "/export:pt_defeat_victory=metamod_org.pt_defeat_victory")

#pragma comment(linker, "/export:pt_entity_reset=metamod_org.pt_entity_reset")

#pragma comment(linker, "/export:pt_hostage=metamod_org.pt_hostage")

#pragma comment(linker, "/export:pt_mission_target=metamod_org.pt_mission_target")

#pragma comment(linker, "/export:pt_model=metamod_org.pt_model")

#pragma comment(linker, "/export:pt_parachute_area=metamod_org.pt_parachute_area")

#pragma comment(linker, "/export:pt_rescue_zone=metamod_org.pt_rescue_zone")

#pragma comment(linker, "/export:pt_round_info=metamod_org.pt_round_info")

#pragma comment(linker, "/export:pt_score_award=metamod_org.pt_score_award")

#pragma comment(linker, "/export:pt_startpoint=metamod_org.pt_startpoint")

#pragma comment(linker, "/export:pt_timer=metamod_org.pt_timer")

#pragma comment(linker, "/export:pt_toggle_respawnmode=metamod_org.pt_toggle_respawnmode")

#pragma comment(linker, "/export:pt_trigger_bomb=metamod_org.pt_trigger_bomb")

#pragma comment(linker, "/export:pt_trigger_loader=metamod_org.pt_trigger_loader")

#pragma comment(linker, "/export:pt_trigger_zone=metamod_org.pt_trigger_zone")

#pragma comment(linker, "/export:pulse=metamod_org.pulse")

#pragma comment(linker, "/export:pulsefrag=metamod_org.pulsefrag")

#pragma comment(linker, "/export:punch_tripmine=metamod_org.punch_tripmine")

#pragma comment(linker, "/export:push_point1=metamod_org.push_point1")

#pragma comment(linker, "/export:push_point2=metamod_org.push_point2")

#pragma comment(linker, "/export:push_point3=metamod_org.push_point3")

#pragma comment(linker, "/export:push_point4=metamod_org.push_point4")

#pragma comment(linker, "/export:push_point5=metamod_org.push_point5")

#pragma comment(linker, "/export:quake_nail=metamod_org.quake_nail")

#pragma comment(linker, "/export:quake_rocket=metamod_org.quake_rocket")

#pragma comment(linker, "/export:race_controller=metamod_org.race_controller")

#pragma comment(linker, "/export:race_path=metamod_org.race_path")

#pragma comment(linker, "/export:rage=metamod_org.rage")

#pragma comment(linker, "/export:rain_modify=metamod_org.rain_modify")

#pragma comment(linker, "/export:rain_settings=metamod_org.rain_settings")

#pragma comment(linker, "/export:random_ammo=metamod_org.random_ammo")

#pragma comment(linker, "/export:random_speaker=metamod_org.random_speaker")

#pragma comment(linker, "/export:random_trigger=metamod_org.random_trigger")

#pragma comment(linker, "/export:random_weapon=metamod_org.random_weapon")

#pragma comment(linker, "/export:redflag_follow=metamod_org.redflag_follow")

#pragma comment(linker, "/export:reetou_proj=metamod_org.reetou_proj")

#pragma comment(linker, "/export:remove_all_wpts=metamod_org.remove_all_wpts")

#pragma comment(linker, "/export:remove_wpt=metamod_org.remove_wpt")

#pragma comment(linker, "/export:resourcetower=metamod_org.resourcetower")

#pragma comment(linker, "/export:respawn_chest=metamod_org.respawn_chest")

#pragma comment(linker, "/export:return_axe=metamod_org.return_axe")

#pragma comment(linker, "/export:reversecurse=metamod_org.reversecurse")

#pragma comment(linker, "/export:rm_rocket=metamod_org.rm_rocket")

#pragma comment(linker, "/export:roach_charge=metamod_org.roach_charge")

#pragma comment(linker, "/export:rocket_air_strike=metamod_org.rocket_air_strike")

#pragma comment(linker, "/export:rocket_croix=metamod_org.rocket_croix")

#pragma comment(linker, "/export:rocket_mine=metamod_org.rocket_mine")

#pragma comment(linker, "/export:rocket_napalm=metamod_org.rocket_napalm")

#pragma comment(linker, "/export:rocket_phoenix=metamod_org.rocket_phoenix")

#pragma comment(linker, "/export:rocket_pigeon=metamod_org.rocket_pigeon")

#pragma comment(linker, "/export:rocket_snipe=metamod_org.rocket_snipe")

#pragma comment(linker, "/export:rocketpistol_rocket=metamod_org.rocketpistol_rocket")

#pragma comment(linker, "/export:rope_sample=metamod_org.rope_sample")

#pragma comment(linker, "/export:rope_segment=metamod_org.rope_segment")

#pragma comment(linker, "/export:rpg7_rocket=metamod_org.rpg7_rocket")

#pragma comment(linker, "/export:rpg_rocket=metamod_org.rpg_rocket")

#pragma comment(linker, "/export:rr_shell=metamod_org.rr_shell")

#pragma comment(linker, "/export:rrp=metamod_org.rrp")

#pragma comment(linker, "/export:rs_effect=metamod_org.rs_effect")

#pragma comment(linker, "/export:rs_fog=metamod_org.rs_fog")

#pragma comment(linker, "/export:rs_grenade=metamod_org.rs_grenade")

#pragma comment(linker, "/export:rs_if=metamod_org.rs_if")

#pragma comment(linker, "/export:rs_message=metamod_org.rs_message")

#pragma comment(linker, "/export:rs_particle_emitter=metamod_org.rs_particle_emitter")

#pragma comment(linker, "/export:rs_roundend=metamod_org.rs_roundend")

#pragma comment(linker, "/export:rs_teamslot=metamod_org.rs_teamslot")

#pragma comment(linker, "/export:rs_timer=metamod_org.rs_timer")

#pragma comment(linker, "/export:rs_val=metamod_org.rs_val")

#pragma comment(linker, "/export:rs_victorypoints=metamod_org.rs_victorypoints")

#pragma comment(linker, "/export:sams_shower=metamod_org.sams_shower")

#pragma comment(linker, "/export:sanity=metamod_org.sanity")

#pragma comment(linker, "/export:satelite_laser=metamod_org.satelite_laser")

#pragma comment(linker, "/export:save_wpt=metamod_org.save_wpt")

#pragma comment(linker, "/export:scan=metamod_org.scan")

#pragma comment(linker, "/export:scatterattack=metamod_org.scatterattack")

#pragma comment(linker, "/export:scattersplit=metamod_org.scattersplit")

#pragma comment(linker, "/export:sci_spawner=metamod_org.sci_spawner")

#pragma comment(linker, "/export:scientist_mine=metamod_org.scientist_mine")

#pragma comment(linker, "/export:scientistbomb=metamod_org.scientistbomb")

#pragma comment(linker, "/export:score_multiplier=metamod_org.score_multiplier")

#pragma comment(linker, "/export:scoreboard=metamod_org.scoreboard")

#pragma comment(linker, "/export:scripted=metamod_org.scripted")

#pragma comment(linker, "/export:scripted_action=metamod_org.scripted_action")

#pragma comment(linker, "/export:scripted_sentence=metamod_org.scripted_sentence")

#pragma comment(linker, "/export:scripted_sequence=metamod_org.scripted_sequence")

#pragma comment(linker, "/export:scripted_tanksequence=metamod_org.scripted_tanksequence")

#pragma comment(linker, "/export:scripted_trainsequence=metamod_org.scripted_trainsequence")

#pragma comment(linker, "/export:sdcurse=metamod_org.sdcurse")

#pragma comment(linker, "/export:secondary_point=metamod_org.secondary_point")

#pragma comment(linker, "/export:securitymanager=metamod_org.securitymanager")

#pragma comment(linker, "/export:sell_ak101=metamod_org.sell_ak101")

#pragma comment(linker, "/export:sell_ak47=metamod_org.sell_ak47")

#pragma comment(linker, "/export:sell_baretta=metamod_org.sell_baretta")

#pragma comment(linker, "/export:sell_beretta=metamod_org.sell_beretta")

#pragma comment(linker, "/export:sell_dblshot=metamod_org.sell_dblshot")

#pragma comment(linker, "/export:sell_dbshot=metamod_org.sell_dbshot")

#pragma comment(linker, "/export:sell_glock17=metamod_org.sell_glock17")

#pragma comment(linker, "/export:sell_longslide=metamod_org.sell_longslide")

#pragma comment(linker, "/export:sell_mac=metamod_org.sell_mac")

#pragma comment(linker, "/export:sell_mac10=metamod_org.sell_mac10")

#pragma comment(linker, "/export:sell_molotov_cocktail=metamod_org.sell_molotov_cocktail")

#pragma comment(linker, "/export:sell_mossberg=metamod_org.sell_mossberg")

#pragma comment(linker, "/export:sell_psg1=metamod_org.sell_psg1")

#pragma comment(linker, "/export:sell_steyr_m40=metamod_org.sell_steyr_m40")

#pragma comment(linker, "/export:sell_tec9=metamod_org.sell_tec9")

#pragma comment(linker, "/export:sell_tommy=metamod_org.sell_tommy")

#pragma comment(linker, "/export:sell_tommygun=metamod_org.sell_tommygun")

#pragma comment(linker, "/export:sell_uzi=metamod_org.sell_uzi")

#pragma comment(linker, "/export:sensorychamber=metamod_org.sensorychamber")

#pragma comment(linker, "/export:sgvortex=metamod_org.sgvortex")

#pragma comment(linker, "/export:shell_bazooka=metamod_org.shell_bazooka")

#pragma comment(linker, "/export:shell_piat=metamod_org.shell_piat")

#pragma comment(linker, "/export:shell_pschreck=metamod_org.shell_pschreck")

#pragma comment(linker, "/export:shenlong=metamod_org.shenlong")

#pragma comment(linker, "/export:shipAI_shipmate=metamod_org.shipAI_shipmate")

#pragma comment(linker, "/export:shock=metamod_org.shock")

#pragma comment(linker, "/export:shockH=metamod_org.shockH")

#pragma comment(linker, "/export:shock_beam=metamod_org.shock_beam")

#pragma comment(linker, "/export:shockcore=metamod_org.shockcore")

#pragma comment(linker, "/export:shotgun_crate=metamod_org.shotgun_crate")

#pragma comment(linker, "/export:shotgun_forklift=metamod_org.shotgun_forklift")

#pragma comment(linker, "/export:shotgun_hev=metamod_org.shotgun_hev")

#pragma comment(linker, "/export:shotgun_sci=metamod_org.shotgun_sci")

#pragma comment(linker, "/export:show_wpt=metamod_org.show_wpt")

#pragma comment(linker, "/export:shrapnel=metamod_org.shrapnel")

#pragma comment(linker, "/export:shrink_timer=metamod_org.shrink_timer")

#pragma comment(linker, "/export:shrinker_project=metamod_org.shrinker_project")

#pragma comment(linker, "/export:siegeturret=metamod_org.siegeturret")

#pragma comment(linker, "/export:skull=metamod_org.skull")

#pragma comment(linker, "/export:skunk_fart=metamod_org.skunk_fart")

#pragma comment(linker, "/export:slAGruntTakeCoverFromEnemy=metamod_org.slAGruntTakeCoverFromEnemy")

#pragma comment(linker, "/export:slAGruntThreatDisplay=metamod_org.slAGruntThreatDisplay")

#pragma comment(linker, "/export:slAssassinTakeCoverFromBestSound=metamod_org.slAssassinTakeCoverFromBestSound")

#pragma comment(linker, "/export:slAssassinTakeCoverFromEnemy=metamod_org.slAssassinTakeCoverFromEnemy")

#pragma comment(linker, "/export:slAssassinTakeCoverFromEnemy2=metamod_org.slAssassinTakeCoverFromEnemy2")

#pragma comment(linker, "/export:slBaFaceTarget=metamod_org.slBaFaceTarget")

#pragma comment(linker, "/export:slControllerTakeCover=metamod_org.slControllerTakeCover")

#pragma comment(linker, "/export:slFaceTarget=metamod_org.slFaceTarget")

#pragma comment(linker, "/export:slFaceTargetScared=metamod_org.slFaceTargetScared")

#pragma comment(linker, "/export:slGruntTakeCover=metamod_org.slGruntTakeCover")

#pragma comment(linker, "/export:slGruntTakeCoverFromBestSound=metamod_org.slGruntTakeCoverFromBestSound")

#pragma comment(linker, "/export:slGruntTossGrenadeCover=metamod_org.slGruntTossGrenadeCover")

#pragma comment(linker, "/export:slIdleTrigger=metamod_org.slIdleTrigger")

#pragma comment(linker, "/export:slRunToScript=metamod_org.slRunToScript")

#pragma comment(linker, "/export:slTakeCoverFromBestSound=metamod_org.slTakeCoverFromBestSound")

#pragma comment(linker, "/export:slTakeCoverFromEnemy=metamod_org.slTakeCoverFromEnemy")

#pragma comment(linker, "/export:slTakeCoverFromOrigin=metamod_org.slTakeCoverFromOrigin")

#pragma comment(linker, "/export:slTlkIdleEyecontact=metamod_org.slTlkIdleEyecontact")

#pragma comment(linker, "/export:slTlkIdleWatchClient=metamod_org.slTlkIdleWatchClient")

#pragma comment(linker, "/export:slTwitchDie=metamod_org.slTwitchDie")

#pragma comment(linker, "/export:slWalkToScript=metamod_org.slWalkToScript")

#pragma comment(linker, "/export:slowcurse=metamod_org.slowcurse")

#pragma comment(linker, "/export:slowrefirecurse=metamod_org.slowrefirecurse")

#pragma comment(linker, "/export:sm_project=metamod_org.sm_project")

#pragma comment(linker, "/export:sm_rocket_01=metamod_org.sm_rocket_01")

#pragma comment(linker, "/export:smoking_grenade=metamod_org.smoking_grenade")

#pragma comment(linker, "/export:snark_cam=metamod_org.snark_cam")

#pragma comment(linker, "/export:snark_project=metamod_org.snark_project")

#pragma comment(linker, "/export:snowball=metamod_org.snowball")

#pragma comment(linker, "/export:soundent=metamod_org.soundent")

#pragma comment(linker, "/export:spark_shower=metamod_org.spark_shower")

#pragma comment(linker, "/export:spawn_base_team1=metamod_org.spawn_base_team1")

#pragma comment(linker, "/export:spawn_base_team2=metamod_org.spawn_base_team2")

#pragma comment(linker, "/export:spawn_observer=metamod_org.spawn_observer")

#pragma comment(linker, "/export:spawn_player_custom=metamod_org.spawn_player_custom")

#pragma comment(linker, "/export:spawn_player_team1=metamod_org.spawn_player_team1")

#pragma comment(linker, "/export:spawn_player_team2=metamod_org.spawn_player_team2")

#pragma comment(linker, "/export:spawnfar=metamod_org.spawnfar")

#pragma comment(linker, "/export:speaker=metamod_org.speaker")

#pragma comment(linker, "/export:spear_bolt=metamod_org.spear_bolt")

#pragma comment(linker, "/export:specailbc=metamod_org.specailbc")

#pragma comment(linker, "/export:special_teleport_in=metamod_org.special_teleport_in")

#pragma comment(linker, "/export:sphere_explosion=metamod_org.sphere_explosion")

#pragma comment(linker, "/export:sphere_mine=metamod_org.sphere_mine")

#pragma comment(linker, "/export:spirit_bomb=metamod_org.spirit_bomb")

#pragma comment(linker, "/export:spitgunprojectile=metamod_org.spitgunprojectile")

#pragma comment(linker, "/export:spore=metamod_org.spore")

#pragma comment(linker, "/export:sporegrenade=metamod_org.sporegrenade")

#pragma comment(linker, "/export:sporegunprojectile=metamod_org.sporegunprojectile")

#pragma comment(linker, "/export:spy_camera=metamod_org.spy_camera")

#pragma comment(linker, "/export:spy_escape=metamod_org.spy_escape")

#pragma comment(linker, "/export:squadmaker=metamod_org.squadmaker")

#pragma comment(linker, "/export:squidspit=metamod_org.squidspit")

#pragma comment(linker, "/export:sstrike=metamod_org.sstrike")

#pragma comment(linker, "/export:st_rocket=metamod_org.st_rocket")

#pragma comment(linker, "/export:streak_spiral=metamod_org.streak_spiral")

#pragma comment(linker, "/export:struct_goa=metamod_org.struct_goa")

#pragma comment(linker, "/export:struct_goa_actual=metamod_org.struct_goa_actual")

#pragma comment(linker, "/export:struct_goa_actual_sub=metamod_org.struct_goa_actual_sub")

#pragma comment(linker, "/export:struct_tau=metamod_org.struct_tau")

#pragma comment(linker, "/export:struct_tau_actual=metamod_org.struct_tau_actual")

#pragma comment(linker, "/export:struct_tau_actual_sub=metamod_org.struct_tau_actual_sub")

#pragma comment(linker, "/export:sturmbody=metamod_org.sturmbody")

#pragma comment(linker, "/export:suck_grenade=metamod_org.suck_grenade")

#pragma comment(linker, "/export:suck_mine=metamod_org.suck_mine")

#pragma comment(linker, "/export:sunofgod=metamod_org.sunofgod")

#pragma comment(linker, "/export:swarm_garg_stomp=metamod_org.swarm_garg_stomp")

#pragma comment(linker, "/export:swarm_spawnpt_acontroller=metamod_org.swarm_spawnpt_acontroller")

#pragma comment(linker, "/export:swarm_spawnpt_agarg=metamod_org.swarm_spawnpt_agarg")

#pragma comment(linker, "/export:swarm_spawnpt_aheadcrab=metamod_org.swarm_spawnpt_aheadcrab")

#pragma comment(linker, "/export:swarm_spawnpt_aslave=metamod_org.swarm_spawnpt_aslave")

#pragma comment(linker, "/export:swarm_spawnpt_atripod=metamod_org.swarm_spawnpt_atripod")

#pragma comment(linker, "/export:swarm_spawnpt_hassassin=metamod_org.swarm_spawnpt_hassassin")

#pragma comment(linker, "/export:swarm_spawnpt_hcommander=metamod_org.swarm_spawnpt_hcommander")

#pragma comment(linker, "/export:swarm_spawnpt_hengineer=metamod_org.swarm_spawnpt_hengineer")

#pragma comment(linker, "/export:swarm_spawnpt_hgrunt=metamod_org.swarm_spawnpt_hgrunt")

#pragma comment(linker, "/export:swarm_spawnpt_hscientist=metamod_org.swarm_spawnpt_hscientist")

#pragma comment(linker, "/export:swarm_spawnpt_human=metamod_org.swarm_spawnpt_human")

#pragma comment(linker, "/export:swarm_team_alien=metamod_org.swarm_team_alien")

#pragma comment(linker, "/export:swarm_team_human=metamod_org.swarm_team_human")

#pragma comment(linker, "/export:tag_camp=metamod_org.tag_camp")

#pragma comment(linker, "/export:tag_crouch_jump=metamod_org.tag_crouch_jump")

#pragma comment(linker, "/export:tag_door=metamod_org.tag_door")

#pragma comment(linker, "/export:tag_duck=metamod_org.tag_duck")

#pragma comment(linker, "/export:tag_jump=metamod_org.tag_jump")

#pragma comment(linker, "/export:tag_run=metamod_org.tag_run")

#pragma comment(linker, "/export:tag_snipe=metamod_org.tag_snipe")

#pragma comment(linker, "/export:tag_walk=metamod_org.tag_walk")

#pragma comment(linker, "/export:tango_nomad=metamod_org.tango_nomad")

#pragma comment(linker, "/export:tango_sentinel=metamod_org.tango_sentinel")

#pragma comment(linker, "/export:tango_sniper=metamod_org.tango_sniper")

#pragma comment(linker, "/export:targ_speaker=metamod_org.targ_speaker")

#pragma comment(linker, "/export:target_all_players=metamod_org.target_all_players")

#pragma comment(linker, "/export:target_animation=metamod_org.target_animation")

#pragma comment(linker, "/export:target_cdaudio=metamod_org.target_cdaudio")

#pragma comment(linker, "/export:target_changemaster=metamod_org.target_changemaster")

#pragma comment(linker, "/export:target_changetarget=metamod_org.target_changetarget")

#pragma comment(linker, "/export:target_give=metamod_org.target_give")

#pragma comment(linker, "/export:target_gravity=metamod_org.target_gravity")

#pragma comment(linker, "/export:target_help=metamod_org.target_help")

#pragma comment(linker, "/export:target_hurt=metamod_org.target_hurt")

#pragma comment(linker, "/export:target_kill=metamod_org.target_kill")

#pragma comment(linker, "/export:target_mp3audio=metamod_org.target_mp3audio")

#pragma comment(linker, "/export:target_print=metamod_org.target_print")

#pragma comment(linker, "/export:target_push=metamod_org.target_push")

#pragma comment(linker, "/export:target_random=metamod_org.target_random")

#pragma comment(linker, "/export:target_random_player=metamod_org.target_random_player")

#pragma comment(linker, "/export:target_relay=metamod_org.target_relay")

#pragma comment(linker, "/export:target_removeobject=metamod_org.target_removeobject")

#pragma comment(linker, "/export:target_reset=metamod_org.target_reset")

#pragma comment(linker, "/export:target_respawn=metamod_org.target_respawn")

#pragma comment(linker, "/export:target_score=metamod_org.target_score")

#pragma comment(linker, "/export:target_server_command=metamod_org.target_server_command")

#pragma comment(linker, "/export:target_set_cvar=metamod_org.target_set_cvar")

#pragma comment(linker, "/export:target_spawnitem=metamod_org.target_spawnitem")

#pragma comment(linker, "/export:target_spectate=metamod_org.target_spectate")

#pragma comment(linker, "/export:target_team=metamod_org.target_team")

#pragma comment(linker, "/export:target_team_score=metamod_org.target_team_score")

#pragma comment(linker, "/export:target_teamdie=metamod_org.target_teamdie")

#pragma comment(linker, "/export:target_teleport=metamod_org.target_teleport")

#pragma comment(linker, "/export:target_tripmine=metamod_org.target_tripmine")

#pragma comment(linker, "/export:target_weaponstrip=metamod_org.target_weaponstrip")

#pragma comment(linker, "/export:target_win=metamod_org.target_win")

#pragma comment(linker, "/export:tcontroller_cball=metamod_org.tcontroller_cball")

#pragma comment(linker, "/export:tcontroller_tball=metamod_org.tcontroller_tball")

#pragma comment(linker, "/export:team_advarmory=metamod_org.team_advarmory")

#pragma comment(linker, "/export:team_advturretfactory=metamod_org.team_advturretfactory")

#pragma comment(linker, "/export:team_armory=metamod_org.team_armory")

#pragma comment(linker, "/export:team_armslab=metamod_org.team_armslab")

#pragma comment(linker, "/export:team_chemlab=metamod_org.team_chemlab")

#pragma comment(linker, "/export:team_command=metamod_org.team_command")

#pragma comment(linker, "/export:team_goal=metamod_org.team_goal")

#pragma comment(linker, "/export:team_hive=metamod_org.team_hive")

#pragma comment(linker, "/export:team_infportal=metamod_org.team_infportal")

#pragma comment(linker, "/export:team_medlab=metamod_org.team_medlab")

#pragma comment(linker, "/export:team_nukeplant=metamod_org.team_nukeplant")

#pragma comment(linker, "/export:team_observatory=metamod_org.team_observatory")

#pragma comment(linker, "/export:team_prototypelab=metamod_org.team_prototypelab")

#pragma comment(linker, "/export:team_turretfactory=metamod_org.team_turretfactory")

#pragma comment(linker, "/export:team_webstrand=metamod_org.team_webstrand")

#pragma comment(linker, "/export:telebecon=metamod_org.telebecon")

#pragma comment(linker, "/export:teledeath=metamod_org.teledeath")

#pragma comment(linker, "/export:teleenter=metamod_org.teleenter")

#pragma comment(linker, "/export:temp_eject=metamod_org.temp_eject")

#pragma comment(linker, "/export:teslagren=metamod_org.teslagren")

#pragma comment(linker, "/export:test_effect=metamod_org.test_effect")

#pragma comment(linker, "/export:testhull=metamod_org.testhull")

#pragma comment(linker, "/export:testparticles=metamod_org.testparticles")

#pragma comment(linker, "/export:tf_ammo_rpgclip=metamod_org.tf_ammo_rpgclip")

#pragma comment(linker, "/export:tf_flame=metamod_org.tf_flame")

#pragma comment(linker, "/export:tf_flamethrower_burst=metamod_org.tf_flamethrower_burst")

#pragma comment(linker, "/export:tf_gl_grenade=metamod_org.tf_gl_grenade")

#pragma comment(linker, "/export:tf_ic_rocket=metamod_org.tf_ic_rocket")

#pragma comment(linker, "/export:tf_nailgun_nail=metamod_org.tf_nailgun_nail")

#pragma comment(linker, "/export:tf_rpg_rocket=metamod_org.tf_rpg_rocket")

#pragma comment(linker, "/export:tf_weapon_ac=metamod_org.tf_weapon_ac")

#pragma comment(linker, "/export:tf_weapon_autorifle=metamod_org.tf_weapon_autorifle")

#pragma comment(linker, "/export:tf_weapon_axe=metamod_org.tf_weapon_axe")

#pragma comment(linker, "/export:tf_weapon_caltrop=metamod_org.tf_weapon_caltrop")

#pragma comment(linker, "/export:tf_weapon_caltropgrenade=metamod_org.tf_weapon_caltropgrenade")

#pragma comment(linker, "/export:tf_weapon_concussiongrenade=metamod_org.tf_weapon_concussiongrenade")

#pragma comment(linker, "/export:tf_weapon_empgrenade=metamod_org.tf_weapon_empgrenade")

#pragma comment(linker, "/export:tf_weapon_flamethrower=metamod_org.tf_weapon_flamethrower")

#pragma comment(linker, "/export:tf_weapon_gasgrenade=metamod_org.tf_weapon_gasgrenade")

#pragma comment(linker, "/export:tf_weapon_genericprimedgrenade=metamod_org.tf_weapon_genericprimedgrenade")

#pragma comment(linker, "/export:tf_weapon_gl=metamod_org.tf_weapon_gl")

#pragma comment(linker, "/export:tf_weapon_ic=metamod_org.tf_weapon_ic")

#pragma comment(linker, "/export:tf_weapon_knife=metamod_org.tf_weapon_knife")

#pragma comment(linker, "/export:tf_weapon_medikit=metamod_org.tf_weapon_medikit")

#pragma comment(linker, "/export:tf_weapon_mirvbomblet=metamod_org.tf_weapon_mirvbomblet")

#pragma comment(linker, "/export:tf_weapon_mirvgrenade=metamod_org.tf_weapon_mirvgrenade")

#pragma comment(linker, "/export:tf_weapon_nailgrenade=metamod_org.tf_weapon_nailgrenade")

#pragma comment(linker, "/export:tf_weapon_napalmgrenade=metamod_org.tf_weapon_napalmgrenade")

#pragma comment(linker, "/export:tf_weapon_ng=metamod_org.tf_weapon_ng")

#pragma comment(linker, "/export:tf_weapon_normalgrenade=metamod_org.tf_weapon_normalgrenade")

#pragma comment(linker, "/export:tf_weapon_pl=metamod_org.tf_weapon_pl")

#pragma comment(linker, "/export:tf_weapon_railgun=metamod_org.tf_weapon_railgun")

#pragma comment(linker, "/export:tf_weapon_rpg=metamod_org.tf_weapon_rpg")

#pragma comment(linker, "/export:tf_weapon_shotgun=metamod_org.tf_weapon_shotgun")

#pragma comment(linker, "/export:tf_weapon_sniperrifle=metamod_org.tf_weapon_sniperrifle")

#pragma comment(linker, "/export:tf_weapon_spanner=metamod_org.tf_weapon_spanner")

#pragma comment(linker, "/export:tf_weapon_superng=metamod_org.tf_weapon_superng")

#pragma comment(linker, "/export:tf_weapon_supershotgun=metamod_org.tf_weapon_supershotgun")

#pragma comment(linker, "/export:tf_weapon_tranq=metamod_org.tf_weapon_tranq")

#pragma comment(linker, "/export:tgrenade=metamod_org.tgrenade")

#pragma comment(linker, "/export:thornbush=metamod_org.thornbush")

#pragma comment(linker, "/export:throwing_knife=metamod_org.throwing_knife")

#pragma comment(linker, "/export:thrown_katana=metamod_org.thrown_katana")

#pragma comment(linker, "/export:thrown_knife=metamod_org.thrown_knife")

#pragma comment(linker, "/export:thrown_object=metamod_org.thrown_object")

#pragma comment(linker, "/export:thrown_sledge=metamod_org.thrown_sledge")

#pragma comment(linker, "/export:timed_grenade=metamod_org.timed_grenade")

#pragma comment(linker, "/export:timedevent=metamod_org.timedevent")

#pragma comment(linker, "/export:timer=metamod_org.timer")

#pragma comment(linker, "/export:timer_add=metamod_org.timer_add")

#pragma comment(linker, "/export:tlAGruntTakeCoverFromEnemy=metamod_org.tlAGruntTakeCoverFromEnemy")

#pragma comment(linker, "/export:tlAGruntThreatDisplay=metamod_org.tlAGruntThreatDisplay")

#pragma comment(linker, "/export:tlAssassinTakeCoverFromBestSound=metamod_org.tlAssassinTakeCoverFromBestSound")

#pragma comment(linker, "/export:tlAssassinTakeCoverFromEnemy=metamod_org.tlAssassinTakeCoverFromEnemy")

#pragma comment(linker, "/export:tlAssassinTakeCoverFromEnemy2=metamod_org.tlAssassinTakeCoverFromEnemy2")

#pragma comment(linker, "/export:tlBaFaceTarget=metamod_org.tlBaFaceTarget")

#pragma comment(linker, "/export:tlControllerTakeCover=metamod_org.tlControllerTakeCover")

#pragma comment(linker, "/export:tlFaceTarget=metamod_org.tlFaceTarget")

#pragma comment(linker, "/export:tlFaceTargetScared=metamod_org.tlFaceTargetScared")

#pragma comment(linker, "/export:tlGruntTakeCover1=metamod_org.tlGruntTakeCover1")

#pragma comment(linker, "/export:tlGruntTakeCoverFromBestSound=metamod_org.tlGruntTakeCoverFromBestSound")

#pragma comment(linker, "/export:tlGruntTossGrenadeCover1=metamod_org.tlGruntTossGrenadeCover1")

#pragma comment(linker, "/export:tlTakeCoverFromBestSound=metamod_org.tlTakeCoverFromBestSound")

#pragma comment(linker, "/export:tlTakeCoverFromEnemy=metamod_org.tlTakeCoverFromEnemy")

#pragma comment(linker, "/export:tlTakeCoverFromOrigin=metamod_org.tlTakeCoverFromOrigin")

#pragma comment(linker, "/export:tlTlkIdleEyecontact=metamod_org.tlTlkIdleEyecontact")

#pragma comment(linker, "/export:tlTlkIdleWatchClient=metamod_org.tlTlkIdleWatchClient")

#pragma comment(linker, "/export:tlTlkIdleWatchClientStare=metamod_org.tlTlkIdleWatchClientStare")

#pragma comment(linker, "/export:tlTwitchDie=metamod_org.tlTwitchDie")

#pragma comment(linker, "/export:tod_control_area=metamod_org.tod_control_area")

#pragma comment(linker, "/export:tod_control_point=metamod_org.tod_control_point")

#pragma comment(linker, "/export:tod_notripmine_area=metamod_org.tod_notripmine_area")

#pragma comment(linker, "/export:tod_roundend_trigger=metamod_org.tod_roundend_trigger")

#pragma comment(linker, "/export:tod_roundstart_trigger=metamod_org.tod_roundstart_trigger")

#pragma comment(linker, "/export:tod_roundwon_trigger=metamod_org.tod_roundwon_trigger")

#pragma comment(linker, "/export:tombstone=metamod_org.tombstone")

#pragma comment(linker, "/export:translocator_disc=metamod_org.translocator_disc")

#pragma comment(linker, "/export:transphasic_gib=metamod_org.transphasic_gib")

#pragma comment(linker, "/export:transport_apc=metamod_org.transport_apc")

#pragma comment(linker, "/export:transport_blackhawk=metamod_org.transport_blackhawk")

#pragma comment(linker, "/export:treasure_chest=metamod_org.treasure_chest")

#pragma comment(linker, "/export:trenches_allied_start=metamod_org.trenches_allied_start")

#pragma comment(linker, "/export:trenches_axis_start=metamod_org.trenches_axis_start")

#pragma comment(linker, "/export:trenches_central_start=metamod_org.trenches_central_start")

#pragma comment(linker, "/export:trigger=metamod_org.trigger")

#pragma comment(linker, "/export:trigger_GoalLine=metamod_org.trigger_GoalLine")

#pragma comment(linker, "/export:trigger_PenaltyBox=metamod_org.trigger_PenaltyBox")

#pragma comment(linker, "/export:trigger_SideLine=metamod_org.trigger_SideLine")

#pragma comment(linker, "/export:trigger_adv_teleport=metamod_org.trigger_adv_teleport")

#pragma comment(linker, "/export:trigger_armory=metamod_org.trigger_armory")

#pragma comment(linker, "/export:trigger_assault=metamod_org.trigger_assault")

#pragma comment(linker, "/export:trigger_auto=metamod_org.trigger_auto")

#pragma comment(linker, "/export:trigger_autosave=metamod_org.trigger_autosave")

#pragma comment(linker, "/export:trigger_ball=metamod_org.trigger_ball")

#pragma comment(linker, "/export:trigger_baril=metamod_org.trigger_baril")

#pragma comment(linker, "/export:trigger_bounce=metamod_org.trigger_bounce")

#pragma comment(linker, "/export:trigger_camera=metamod_org.trigger_camera")

#pragma comment(linker, "/export:trigger_capturetimer=metamod_org.trigger_capturetimer")

#pragma comment(linker, "/export:trigger_captureupdate=metamod_org.trigger_captureupdate")

#pragma comment(linker, "/export:trigger_cdaudio=metamod_org.trigger_cdaudio")

#pragma comment(linker, "/export:trigger_changealias=metamod_org.trigger_changealias")

#pragma comment(linker, "/export:trigger_changecvar=metamod_org.trigger_changecvar")

#pragma comment(linker, "/export:trigger_changelevel=metamod_org.trigger_changelevel")

#pragma comment(linker, "/export:trigger_changetarget=metamod_org.trigger_changetarget")

#pragma comment(linker, "/export:trigger_changevalue=metamod_org.trigger_changevalue")

#pragma comment(linker, "/export:trigger_coldbreath=metamod_org.trigger_coldbreath")

#pragma comment(linker, "/export:trigger_comet=metamod_org.trigger_comet")

#pragma comment(linker, "/export:trigger_command=metamod_org.trigger_command")

#pragma comment(linker, "/export:trigger_control=metamod_org.trigger_control")

#pragma comment(linker, "/export:trigger_coop=metamod_org.trigger_coop")

#pragma comment(linker, "/export:trigger_counter=metamod_org.trigger_counter")

#pragma comment(linker, "/export:trigger_course=metamod_org.trigger_course")

#pragma comment(linker, "/export:trigger_crash=metamod_org.trigger_crash")

#pragma comment(linker, "/export:trigger_ctf=metamod_org.trigger_ctf")

#pragma comment(linker, "/export:trigger_ctfgeneric=metamod_org.trigger_ctfgeneric")

#pragma comment(linker, "/export:trigger_deathmatch=metamod_org.trigger_deathmatch")

#pragma comment(linker, "/export:trigger_deliveryzone=metamod_org.trigger_deliveryzone")

#pragma comment(linker, "/export:trigger_die=metamod_org.trigger_die")

#pragma comment(linker, "/export:trigger_discerturn=metamod_org.trigger_discerturn")

#pragma comment(linker, "/export:trigger_discreturn=metamod_org.trigger_discreturn")

#pragma comment(linker, "/export:trigger_endround=metamod_org.trigger_endround")

#pragma comment(linker, "/export:trigger_endsection=metamod_org.trigger_endsection")

#pragma comment(linker, "/export:trigger_env_hurt=metamod_org.trigger_env_hurt")

#pragma comment(linker, "/export:trigger_execcommand=metamod_org.trigger_execcommand")

#pragma comment(linker, "/export:trigger_fall=metamod_org.trigger_fall")

#pragma comment(linker, "/export:trigger_flagcheck=metamod_org.trigger_flagcheck")

#pragma comment(linker, "/export:trigger_geneworm_hit=metamod_org.trigger_geneworm_hit")

#pragma comment(linker, "/export:trigger_goal=metamod_org.trigger_goal")

#pragma comment(linker, "/export:trigger_golem=metamod_org.trigger_golem")

#pragma comment(linker, "/export:trigger_gravity=metamod_org.trigger_gravity")

#pragma comment(linker, "/export:trigger_gunmanteleport=metamod_org.trigger_gunmanteleport")

#pragma comment(linker, "/export:trigger_hevcharge=metamod_org.trigger_hevcharge")

#pragma comment(linker, "/export:trigger_hold=metamod_org.trigger_hold")

#pragma comment(linker, "/export:trigger_hurt=metamod_org.trigger_hurt")

#pragma comment(linker, "/export:trigger_hurt_bleu=metamod_org.trigger_hurt_bleu")

#pragma comment(linker, "/export:trigger_hurt_rouge=metamod_org.trigger_hurt_rouge")

#pragma comment(linker, "/export:trigger_inout=metamod_org.trigger_inout")

#pragma comment(linker, "/export:trigger_jail=metamod_org.trigger_jail")

#pragma comment(linker, "/export:trigger_jail_release=metamod_org.trigger_jail_release")

#pragma comment(linker, "/export:trigger_jetpack=metamod_org.trigger_jetpack")

#pragma comment(linker, "/export:trigger_jump=metamod_org.trigger_jump")

#pragma comment(linker, "/export:trigger_jumppad=metamod_org.trigger_jumppad")

#pragma comment(linker, "/export:trigger_katehealth=metamod_org.trigger_katehealth")

#pragma comment(linker, "/export:trigger_kill_nogib=metamod_org.trigger_kill_nogib")

#pragma comment(linker, "/export:trigger_killmonster=metamod_org.trigger_killmonster")

#pragma comment(linker, "/export:trigger_lightstyle=metamod_org.trigger_lightstyle")

#pragma comment(linker, "/export:trigger_loadhazard=metamod_org.trigger_loadhazard")

#pragma comment(linker, "/export:trigger_mine=metamod_org.trigger_mine")

#pragma comment(linker, "/export:trigger_monsterjump=metamod_org.trigger_monsterjump")

#pragma comment(linker, "/export:trigger_motion=metamod_org.trigger_motion")

#pragma comment(linker, "/export:trigger_multiple=metamod_org.trigger_multiple")

#pragma comment(linker, "/export:trigger_music=metamod_org.trigger_music")

#pragma comment(linker, "/export:trigger_noclaymores=metamod_org.trigger_noclaymores")

#pragma comment(linker, "/export:trigger_npcarea=metamod_org.trigger_npcarea")

#pragma comment(linker, "/export:trigger_objectcapture=metamod_org.trigger_objectcapture")

#pragma comment(linker, "/export:trigger_once=metamod_org.trigger_once")

#pragma comment(linker, "/export:trigger_once_round=metamod_org.trigger_once_round")

#pragma comment(linker, "/export:trigger_onsight=metamod_org.trigger_onsight")

#pragma comment(linker, "/export:trigger_particles=metamod_org.trigger_particles")

#pragma comment(linker, "/export:trigger_playerfreeze=metamod_org.trigger_playerfreeze")

#pragma comment(linker, "/export:trigger_point_controle=metamod_org.trigger_point_controle")

#pragma comment(linker, "/export:trigger_presence=metamod_org.trigger_presence")

#pragma comment(linker, "/export:trigger_push=metamod_org.trigger_push")

#pragma comment(linker, "/export:trigger_random=metamod_org.trigger_random")

#pragma comment(linker, "/export:trigger_random_group=metamod_org.trigger_random_group")

#pragma comment(linker, "/export:trigger_random_time=metamod_org.trigger_random_time")

#pragma comment(linker, "/export:trigger_random_unique=metamod_org.trigger_random_unique")

#pragma comment(linker, "/export:trigger_regen=metamod_org.trigger_regen")

#pragma comment(linker, "/export:trigger_reinforcements=metamod_org.trigger_reinforcements")

#pragma comment(linker, "/export:trigger_relay=metamod_org.trigger_relay")

#pragma comment(linker, "/export:trigger_respawn=metamod_org.trigger_respawn")

#pragma comment(linker, "/export:trigger_rndbased=metamod_org.trigger_rndbased")

#pragma comment(linker, "/export:trigger_rottest=metamod_org.trigger_rottest")

#pragma comment(linker, "/export:trigger_rs_hurt=metamod_org.trigger_rs_hurt")

#pragma comment(linker, "/export:trigger_script=metamod_org.trigger_script")

#pragma comment(linker, "/export:trigger_secret=metamod_org.trigger_secret")

#pragma comment(linker, "/export:trigger_section=metamod_org.trigger_section")

#pragma comment(linker, "/export:trigger_setflag=metamod_org.trigger_setflag")

#pragma comment(linker, "/export:trigger_setorigin=metamod_org.trigger_setorigin")

#pragma comment(linker, "/export:trigger_shutup=metamod_org.trigger_shutup")

#pragma comment(linker, "/export:trigger_sound=metamod_org.trigger_sound")

#pragma comment(linker, "/export:trigger_speed=metamod_org.trigger_speed")

#pragma comment(linker, "/export:trigger_sponly=metamod_org.trigger_sponly")

#pragma comment(linker, "/export:trigger_startpatrol=metamod_org.trigger_startpatrol")

#pragma comment(linker, "/export:trigger_teampush=metamod_org.trigger_teampush")

#pragma comment(linker, "/export:trigger_teleport=metamod_org.trigger_teleport")

#pragma comment(linker, "/export:trigger_transition=metamod_org.trigger_transition")

#pragma comment(linker, "/export:trigger_war=metamod_org.trigger_war")

#pragma comment(linker, "/export:trigger_xen_return=metamod_org.trigger_xen_return")

#pragma comment(linker, "/export:trigger_zone=metamod_org.trigger_zone")

#pragma comment(linker, "/export:trigger_zone_bleu=metamod_org.trigger_zone_bleu")

#pragma comment(linker, "/export:trigger_zone_rouge=metamod_org.trigger_zone_rouge")

#pragma comment(linker, "/export:trip_beam=metamod_org.trip_beam")

#pragma comment(linker, "/export:ts_bomb=metamod_org.ts_bomb")

#pragma comment(linker, "/export:ts_dmhill=metamod_org.ts_dmhill")

#pragma comment(linker, "/export:ts_groundweapon=metamod_org.ts_groundweapon")

#pragma comment(linker, "/export:ts_hack=metamod_org.ts_hack")

#pragma comment(linker, "/export:ts_mapglobals=metamod_org.ts_mapglobals")

#pragma comment(linker, "/export:ts_model=metamod_org.ts_model")

#pragma comment(linker, "/export:ts_objective_manager=metamod_org.ts_objective_manager")

#pragma comment(linker, "/export:ts_objective_ptr=metamod_org.ts_objective_ptr")

#pragma comment(linker, "/export:ts_powerup=metamod_org.ts_powerup")

#pragma comment(linker, "/export:ts_slowmotion=metamod_org.ts_slowmotion")

#pragma comment(linker, "/export:ts_slowmotionpoint=metamod_org.ts_slowmotionpoint")

#pragma comment(linker, "/export:ts_teamescape=metamod_org.ts_teamescape")

#pragma comment(linker, "/export:ts_trigger=metamod_org.ts_trigger")

#pragma comment(linker, "/export:ts_vipescape=metamod_org.ts_vipescape")

#pragma comment(linker, "/export:ts_wingiver=metamod_org.ts_wingiver")

#pragma comment(linker, "/export:turf_zone=metamod_org.turf_zone")

#pragma comment(linker, "/export:turret=metamod_org.turret")

#pragma comment(linker, "/export:ultima_grenade=metamod_org.ultima_grenade")

#pragma comment(linker, "/export:umbracloud=metamod_org.umbracloud")

#pragma comment(linker, "/export:umbraprojectile=metamod_org.umbraprojectile")

#pragma comment(linker, "/export:uw_monster_hybrid=metamod_org.uw_monster_hybrid")

#pragma comment(linker, "/export:uw_monster_michael=metamod_org.uw_monster_michael")

#pragma comment(linker, "/export:uw_player_lycan=metamod_org.uw_player_lycan")

#pragma comment(linker, "/export:uw_player_vamp=metamod_org.uw_player_vamp")

#pragma comment(linker, "/export:uw_player_view=metamod_org.uw_player_view")

#pragma comment(linker, "/export:vehicle=metamod_org.vehicle")

#pragma comment(linker, "/export:vehicle_dreadnaught=metamod_org.vehicle_dreadnaught")

#pragma comment(linker, "/export:vehicle_dreadnaught_weapon=metamod_org.vehicle_dreadnaught_weapon")

#pragma comment(linker, "/export:vehicle_tank=metamod_org.vehicle_tank")

#pragma comment(linker, "/export:vehicle_thing=metamod_org.vehicle_thing")

#pragma comment(linker, "/export:vehicle_wraithlord=metamod_org.vehicle_wraithlord")

#pragma comment(linker, "/export:vehicle_wraithlord_weapon=metamod_org.vehicle_wraithlord_weapon")

#pragma comment(linker, "/export:victim_scientist=metamod_org.victim_scientist")

#pragma comment(linker, "/export:vipescape=metamod_org.vipescape")

#pragma comment(linker, "/export:virtual_hull=metamod_org.virtual_hull")

#pragma comment(linker, "/export:voltigoreshock=metamod_org.voltigoreshock")

#pragma comment(linker, "/export:vote_llama=metamod_org.vote_llama")

#pragma comment(linker, "/export:vscrossbow_bolt=metamod_org.vscrossbow_bolt")

#pragma comment(linker, "/export:watcher=metamod_org.watcher")

#pragma comment(linker, "/export:watcher_count=metamod_org.watcher_count")

#pragma comment(linker, "/export:weapmortar=metamod_org.weapmortar")

#pragma comment(linker, "/export:weapon_1100=metamod_org.weapon_1100")

#pragma comment(linker, "/export:weapon_1445lda=metamod_org.weapon_1445lda")

#pragma comment(linker, "/export:weapon_1911=metamod_org.weapon_1911")

#pragma comment(linker, "/export:weapon_30cal=metamod_org.weapon_30cal")

#pragma comment(linker, "/export:weapon_30mmsg=metamod_org.weapon_30mmsg")

#pragma comment(linker, "/export:weapon_357=metamod_org.weapon_357")

#pragma comment(linker, "/export:weapon_40gl=metamod_org.weapon_40gl")

#pragma comment(linker, "/export:weapon_44sw=metamod_org.weapon_44sw")

#pragma comment(linker, "/export:weapon_50cal=metamod_org.weapon_50cal")

#pragma comment(linker, "/export:weapon_556AR=metamod_org.weapon_556AR")

#pragma comment(linker, "/export:weapon_90mm=metamod_org.weapon_90mm")

#pragma comment(linker, "/export:weapon_92d=metamod_org.weapon_92d")

#pragma comment(linker, "/export:weapon_9mmAR=metamod_org.weapon_9mmAR")

#pragma comment(linker, "/export:weapon_9mmhandgun=metamod_org.weapon_9mmhandgun")

#pragma comment(linker, "/export:weapon_9mmm41a=metamod_org.weapon_9mmm41a")

#pragma comment(linker, "/export:weapon_BritGrenMelee=metamod_org.weapon_BritGrenMelee")

#pragma comment(linker, "/export:weapon_BritGrenNade=metamod_org.weapon_BritGrenNade")

#pragma comment(linker, "/export:weapon_BrownBess=metamod_org.weapon_BrownBess")

#pragma comment(linker, "/export:weapon_CEnfield=metamod_org.weapon_CEnfield")

#pragma comment(linker, "/export:weapon_CEnfieldMelee=metamod_org.weapon_CEnfieldMelee")

#pragma comment(linker, "/export:weapon_CEnfieldNade=metamod_org.weapon_CEnfieldNade")

#pragma comment(linker, "/export:weapon_Charleville=metamod_org.weapon_Charleville")

#pragma comment(linker, "/export:weapon_FT=metamod_org.weapon_FT")

#pragma comment(linker, "/export:weapon_G11=metamod_org.weapon_G11")

#pragma comment(linker, "/export:weapon_GMauserG98=metamod_org.weapon_GMauserG98")

#pragma comment(linker, "/export:weapon_GMauserG98Melee=metamod_org.weapon_GMauserG98Melee")

#pragma comment(linker, "/export:weapon_GMauserG98Nade=metamod_org.weapon_GMauserG98Nade")

#pragma comment(linker, "/export:weapon_GermGrenMelee=metamod_org.weapon_GermGrenMelee")

#pragma comment(linker, "/export:weapon_GermGrenNade=metamod_org.weapon_GermGrenNade")

#pragma comment(linker, "/export:weapon_Knife=metamod_org.weapon_Knife")

#pragma comment(linker, "/export:weapon_Pennsylvania=metamod_org.weapon_Pennsylvania")

#pragma comment(linker, "/export:weapon_PistolA=metamod_org.weapon_PistolA")

#pragma comment(linker, "/export:weapon_PistolB=metamod_org.weapon_PistolB")

#pragma comment(linker, "/export:weapon_Revolutionnaire=metamod_org.weapon_Revolutionnaire")

#pragma comment(linker, "/export:weapon_SPchemicalgun=metamod_org.weapon_SPchemicalgun")

#pragma comment(linker, "/export:weapon_Sabre=metamod_org.weapon_Sabre")

#pragma comment(linker, "/export:weapon_a5=metamod_org.weapon_a5")

#pragma comment(linker, "/export:weapon_aandagger=metamod_org.weapon_aandagger")

#pragma comment(linker, "/export:weapon_acannon=metamod_org.weapon_acannon")

#pragma comment(linker, "/export:weapon_acidrocket=metamod_org.weapon_acidrocket")

#pragma comment(linker, "/export:weapon_acidrocketgun=metamod_org.weapon_acidrocketgun")

#pragma comment(linker, "/export:weapon_adrenaline=metamod_org.weapon_adrenaline")

#pragma comment(linker, "/export:weapon_aicore=metamod_org.weapon_aicore")

#pragma comment(linker, "/export:weapon_air_strike=metamod_org.weapon_air_strike")

#pragma comment(linker, "/export:weapon_ak=metamod_org.weapon_ak")

#pragma comment(linker, "/export:weapon_ak101=metamod_org.weapon_ak101")

#pragma comment(linker, "/export:weapon_ak47=metamod_org.weapon_ak47")

#pragma comment(linker, "/export:weapon_ak5=metamod_org.weapon_ak5")

#pragma comment(linker, "/export:weapon_ak5s=metamod_org.weapon_ak5s")

#pragma comment(linker, "/export:weapon_ak74=metamod_org.weapon_ak74")

#pragma comment(linker, "/export:weapon_akimbo_glocks=metamod_org.weapon_akimbo_glocks")

#pragma comment(linker, "/export:weapon_akimbob=metamod_org.weapon_akimbob")

#pragma comment(linker, "/export:weapon_akimboberettas=metamod_org.weapon_akimboberettas")

#pragma comment(linker, "/export:weapon_akimbocolts=metamod_org.weapon_akimbocolts")

#pragma comment(linker, "/export:weapon_akimbodeagles=metamod_org.weapon_akimbodeagles")

#pragma comment(linker, "/export:weapon_akimbogun=metamod_org.weapon_akimbogun")

#pragma comment(linker, "/export:weapon_akimbosawedoffs=metamod_org.weapon_akimbosawedoffs")

#pragma comment(linker, "/export:weapon_akimcolt=metamod_org.weapon_akimcolt")

#pragma comment(linker, "/export:weapon_akimsaa=metamod_org.weapon_akimsaa")

#pragma comment(linker, "/export:weapon_aks74u=metamod_org.weapon_aks74u")

#pragma comment(linker, "/export:weapon_alarm=metamod_org.weapon_alarm")

#pragma comment(linker, "/export:weapon_aliencannon=metamod_org.weapon_aliencannon")

#pragma comment(linker, "/export:weapon_amerknife=metamod_org.weapon_amerknife")

#pragma comment(linker, "/export:weapon_ammo=metamod_org.weapon_ammo")

#pragma comment(linker, "/export:weapon_amp=metamod_org.weapon_amp")

#pragma comment(linker, "/export:weapon_anaconda=metamod_org.weapon_anaconda")

#pragma comment(linker, "/export:weapon_angel=metamod_org.weapon_angel")

#pragma comment(linker, "/export:weapon_ar10=metamod_org.weapon_ar10")

#pragma comment(linker, "/export:weapon_ar33=metamod_org.weapon_ar33")

#pragma comment(linker, "/export:weapon_assaultminigun=metamod_org.weapon_assaultminigun")

#pragma comment(linker, "/export:weapon_aug=metamod_org.weapon_aug")

#pragma comment(linker, "/export:weapon_autococker=metamod_org.weapon_autococker")

#pragma comment(linker, "/export:weapon_autogl=metamod_org.weapon_autogl")

#pragma comment(linker, "/export:weapon_automag=metamod_org.weapon_automag")

#pragma comment(linker, "/export:weapon_autoshotgun=metamod_org.weapon_autoshotgun")

#pragma comment(linker, "/export:weapon_awm=metamod_org.weapon_awm")

#pragma comment(linker, "/export:weapon_awp=metamod_org.weapon_awp")

#pragma comment(linker, "/export:weapon_axe=metamod_org.weapon_axe")

#pragma comment(linker, "/export:weapon_axes=metamod_org.weapon_axes")

#pragma comment(linker, "/export:weapon_b93r=metamod_org.weapon_b93r")

#pragma comment(linker, "/export:weapon_babblergun=metamod_org.weapon_babblergun")

#pragma comment(linker, "/export:weapon_babblerprojectile=metamod_org.weapon_babblerprojectile")

#pragma comment(linker, "/export:weapon_balllightningspell=metamod_org.weapon_balllightningspell")

#pragma comment(linker, "/export:weapon_banana=metamod_org.weapon_banana")

#pragma comment(linker, "/export:weapon_banane=metamod_org.weapon_banane")

#pragma comment(linker, "/export:weapon_bandage=metamod_org.weapon_bandage")

#pragma comment(linker, "/export:weapon_bandsaw=metamod_org.weapon_bandsaw")

#pragma comment(linker, "/export:weapon_bang=metamod_org.weapon_bang")

#pragma comment(linker, "/export:weapon_bar=metamod_org.weapon_bar")

#pragma comment(linker, "/export:weapon_barett=metamod_org.weapon_barett")

#pragma comment(linker, "/export:weapon_baretta=metamod_org.weapon_baretta")

#pragma comment(linker, "/export:weapon_barnacle=metamod_org.weapon_barnacle")

#pragma comment(linker, "/export:weapon_barney9mmar=metamod_org.weapon_barney9mmar")

#pragma comment(linker, "/export:weapon_barney9mmhg=metamod_org.weapon_barney9mmhg")

#pragma comment(linker, "/export:weapon_barneyhandgrenade=metamod_org.weapon_barneyhandgrenade")

#pragma comment(linker, "/export:weapon_barneyshotgun=metamod_org.weapon_barneyshotgun")

#pragma comment(linker, "/export:weapon_barrett82=metamod_org.weapon_barrett82")

#pragma comment(linker, "/export:weapon_baseballbat=metamod_org.weapon_baseballbat")

#pragma comment(linker, "/export:weapon_bat=metamod_org.weapon_bat")

#pragma comment(linker, "/export:weapon_baton=metamod_org.weapon_baton")

#pragma comment(linker, "/export:weapon_batsup=metamod_org.weapon_batsup")

#pragma comment(linker, "/export:weapon_batte=metamod_org.weapon_batte")

#pragma comment(linker, "/export:weapon_battleaxe=metamod_org.weapon_battleaxe")

#pragma comment(linker, "/export:weapon_bayonet=metamod_org.weapon_bayonet")

#pragma comment(linker, "/export:weapon_bazooka=metamod_org.weapon_bazooka")

#pragma comment(linker, "/export:weapon_beamgun=metamod_org.weapon_beamgun")

#pragma comment(linker, "/export:weapon_beanstalkspell=metamod_org.weapon_beanstalkspell")

#pragma comment(linker, "/export:weapon_bearbite=metamod_org.weapon_bearbite")

#pragma comment(linker, "/export:weapon_bearclaw=metamod_org.weapon_bearclaw")

#pragma comment(linker, "/export:weapon_beartrap=metamod_org.weapon_beartrap")

#pragma comment(linker, "/export:weapon_benelli=metamod_org.weapon_benelli")

#pragma comment(linker, "/export:weapon_ber92f=metamod_org.weapon_ber92f")

#pragma comment(linker, "/export:weapon_ber92fs=metamod_org.weapon_ber92fs")

#pragma comment(linker, "/export:weapon_ber93r=metamod_org.weapon_ber93r")

#pragma comment(linker, "/export:weapon_beretta=metamod_org.weapon_beretta")

#pragma comment(linker, "/export:weapon_beretta_a=metamod_org.weapon_beretta_a")

#pragma comment(linker, "/export:weapon_bfg=metamod_org.weapon_bfg")

#pragma comment(linker, "/export:weapon_bigaxe=metamod_org.weapon_bigaxe")

#pragma comment(linker, "/export:weapon_bigbang=metamod_org.weapon_bigbang")

#pragma comment(linker, "/export:weapon_biggun=metamod_org.weapon_biggun")

#pragma comment(linker, "/export:weapon_bilebomb=metamod_org.weapon_bilebomb")

#pragma comment(linker, "/export:weapon_bilebombgun=metamod_org.weapon_bilebombgun")

#pragma comment(linker, "/export:weapon_binoculars=metamod_org.weapon_binoculars")

#pragma comment(linker, "/export:weapon_binos=metamod_org.weapon_binos")

#pragma comment(linker, "/export:weapon_birdspell=metamod_org.weapon_birdspell")

#pragma comment(linker, "/export:weapon_bite2gun=metamod_org.weapon_bite2gun")

#pragma comment(linker, "/export:weapon_bitegun=metamod_org.weapon_bitegun")

#pragma comment(linker, "/export:weapon_bizon=metamod_org.weapon_bizon")

#pragma comment(linker, "/export:weapon_blaster=metamod_org.weapon_blaster")

#pragma comment(linker, "/export:weapon_blazer=metamod_org.weapon_blazer")

#pragma comment(linker, "/export:weapon_blink=metamod_org.weapon_blink")

#pragma comment(linker, "/export:weapon_blowpipe=metamod_org.weapon_blowpipe")

#pragma comment(linker, "/export:weapon_bodypart=metamod_org.weapon_bodypart")

#pragma comment(linker, "/export:weapon_bola=metamod_org.weapon_bola")

#pragma comment(linker, "/export:weapon_boltrifle=metamod_org.weapon_boltrifle")

#pragma comment(linker, "/export:weapon_bomb=metamod_org.weapon_bomb")

#pragma comment(linker, "/export:weapon_bomber=metamod_org.weapon_bomber")

#pragma comment(linker, "/export:weapon_bow=metamod_org.weapon_bow")

#pragma comment(linker, "/export:weapon_bren=metamod_org.weapon_bren")

#pragma comment(linker, "/export:weapon_brickcannon=metamod_org.weapon_brickcannon")

#pragma comment(linker, "/export:weapon_briefcase=metamod_org.weapon_briefcase")

#pragma comment(linker, "/export:weapon_bsword=metamod_org.weapon_bsword")

#pragma comment(linker, "/export:weapon_buffalo=metamod_org.weapon_buffalo")

#pragma comment(linker, "/export:weapon_burningattack=metamod_org.weapon_burningattack")

#pragma comment(linker, "/export:weapon_bush=metamod_org.weapon_bush")

#pragma comment(linker, "/export:weapon_bushmaster=metamod_org.weapon_bushmaster")

#pragma comment(linker, "/export:weapon_c4=metamod_org.weapon_c4")

#pragma comment(linker, "/export:weapon_cal50=metamod_org.weapon_cal50")

#pragma comment(linker, "/export:weapon_camera=metamod_org.weapon_camera")

#pragma comment(linker, "/export:weapon_candy=metamod_org.weapon_candy")

#pragma comment(linker, "/export:weapon_canister=metamod_org.weapon_canister")

#pragma comment(linker, "/export:weapon_cannon=metamod_org.weapon_cannon")

#pragma comment(linker, "/export:weapon_case=metamod_org.weapon_case")

#pragma comment(linker, "/export:weapon_cat=metamod_org.weapon_cat")

#pragma comment(linker, "/export:weapon_cattleprod=metamod_org.weapon_cattleprod")

#pragma comment(linker, "/export:weapon_caws=metamod_org.weapon_caws")

#pragma comment(linker, "/export:weapon_ce_lasgun=metamod_org.weapon_ce_lasgun")

#pragma comment(linker, "/export:weapon_ce_powersword=metamod_org.weapon_ce_powersword")

#pragma comment(linker, "/export:weapon_ce_psistaff=metamod_org.weapon_ce_psistaff")

#pragma comment(linker, "/export:weapon_ce_rocketlauncher=metamod_org.weapon_ce_rocketlauncher")

#pragma comment(linker, "/export:weapon_ce_shurikencatapult=metamod_org.weapon_ce_shurikencatapult")

#pragma comment(linker, "/export:weapon_ce_shurikenpistol=metamod_org.weapon_ce_shurikenpistol")

#pragma comment(linker, "/export:weapon_cellphone=metamod_org.weapon_cellphone")

#pragma comment(linker, "/export:weapon_chaingun=metamod_org.weapon_chaingun")

#pragma comment(linker, "/export:weapon_chainsaw=metamod_org.weapon_chainsaw")

#pragma comment(linker, "/export:weapon_charge=metamod_org.weapon_charge")

#pragma comment(linker, "/export:weapon_charged=metamod_org.weapon_charged")

#pragma comment(linker, "/export:weapon_chronosceptor=metamod_org.weapon_chronosceptor")

#pragma comment(linker, "/export:weapon_claw=metamod_org.weapon_claw")

#pragma comment(linker, "/export:weapon_claws=metamod_org.weapon_claws")

#pragma comment(linker, "/export:weapon_claymore=metamod_org.weapon_claymore")

#pragma comment(linker, "/export:weapon_clip_generic=metamod_org.weapon_clip_generic")

#pragma comment(linker, "/export:weapon_cloak=metamod_org.weapon_cloak")

#pragma comment(linker, "/export:weapon_cloaker=metamod_org.weapon_cloaker")

#pragma comment(linker, "/export:weapon_cluster=metamod_org.weapon_cluster")

#pragma comment(linker, "/export:weapon_cm_autocannon=metamod_org.weapon_cm_autocannon")

#pragma comment(linker, "/export:weapon_cm_bolter=metamod_org.weapon_cm_bolter")

#pragma comment(linker, "/export:weapon_cm_bolterflamer=metamod_org.weapon_cm_bolterflamer")

#pragma comment(linker, "/export:weapon_cm_boltpistol=metamod_org.weapon_cm_boltpistol")

#pragma comment(linker, "/export:weapon_cm_chainaxe=metamod_org.weapon_cm_chainaxe")

#pragma comment(linker, "/export:weapon_cm_chainsword=metamod_org.weapon_cm_chainsword")

#pragma comment(linker, "/export:weapon_cm_flamer=metamod_org.weapon_cm_flamer")

#pragma comment(linker, "/export:weapon_cm_fraggrenade=metamod_org.weapon_cm_fraggrenade")

#pragma comment(linker, "/export:weapon_cm_heavybolter=metamod_org.weapon_cm_heavybolter")

#pragma comment(linker, "/export:weapon_cm_lascannon=metamod_org.weapon_cm_lascannon")

#pragma comment(linker, "/export:weapon_cm_missilelauncher=metamod_org.weapon_cm_missilelauncher")

#pragma comment(linker, "/export:weapon_cm_stormbolter=metamod_org.weapon_cm_stormbolter")

#pragma comment(linker, "/export:weapon_cocker=metamod_org.weapon_cocker")

#pragma comment(linker, "/export:weapon_cocogrenade=metamod_org.weapon_cocogrenade")

#pragma comment(linker, "/export:weapon_cocolauncher=metamod_org.weapon_cocolauncher")

#pragma comment(linker, "/export:weapon_colt=metamod_org.weapon_colt")

#pragma comment(linker, "/export:weapon_colt45=metamod_org.weapon_colt45")

#pragma comment(linker, "/export:weapon_coltgov=metamod_org.weapon_coltgov")

#pragma comment(linker, "/export:weapon_colts=metamod_org.weapon_colts")

#pragma comment(linker, "/export:weapon_combatknife=metamod_org.weapon_combatknife")

#pragma comment(linker, "/export:weapon_combospell=metamod_org.weapon_combospell")

#pragma comment(linker, "/export:weapon_cometspell=metamod_org.weapon_cometspell")

#pragma comment(linker, "/export:weapon_concussion=metamod_org.weapon_concussion")

#pragma comment(linker, "/export:weapon_controlled=metamod_org.weapon_controlled")

#pragma comment(linker, "/export:weapon_cougar=metamod_org.weapon_cougar")

#pragma comment(linker, "/export:weapon_coujaf=metamod_org.weapon_coujaf")

#pragma comment(linker, "/export:weapon_couteau=metamod_org.weapon_couteau")

#pragma comment(linker, "/export:weapon_croix=metamod_org.weapon_croix")

#pragma comment(linker, "/export:weapon_crossbow=metamod_org.weapon_crossbow")

#pragma comment(linker, "/export:weapon_crowbar=metamod_org.weapon_crowbar")

#pragma comment(linker, "/export:weapon_crowbar_electric=metamod_org.weapon_crowbar_electric")

#pragma comment(linker, "/export:weapon_cutlass=metamod_org.weapon_cutlass")

#pragma comment(linker, "/export:weapon_cz75=metamod_org.weapon_cz75")

#pragma comment(linker, "/export:weapon_d5k=metamod_org.weapon_d5k")

#pragma comment(linker, "/export:weapon_dagger=metamod_org.weapon_dagger")

#pragma comment(linker, "/export:weapon_daystick=metamod_org.weapon_daystick")

#pragma comment(linker, "/export:weapon_dblpistolet=metamod_org.weapon_dblpistolet")

#pragma comment(linker, "/export:weapon_dblshot=metamod_org.weapon_dblshot")

#pragma comment(linker, "/export:weapon_dbshot=metamod_org.weapon_dbshot")

#pragma comment(linker, "/export:weapon_dd44=metamod_org.weapon_dd44")

#pragma comment(linker, "/export:weapon_de50=metamod_org.weapon_de50")

#pragma comment(linker, "/export:weapon_deagle=metamod_org.weapon_deagle")

#pragma comment(linker, "/export:weapon_deathball=metamod_org.weapon_deathball")

#pragma comment(linker, "/export:weapon_deathrayspell=metamod_org.weapon_deathrayspell")

#pragma comment(linker, "/export:weapon_demo=metamod_org.weapon_demo")

#pragma comment(linker, "/export:weapon_deploygun=metamod_org.weapon_deploygun")

#pragma comment(linker, "/export:weapon_desert=metamod_org.weapon_desert")

#pragma comment(linker, "/export:weapon_deserteagle=metamod_org.weapon_deserteagle")

#pragma comment(linker, "/export:weapon_destructodisc=metamod_org.weapon_destructodisc")

#pragma comment(linker, "/export:weapon_devastator=metamod_org.weapon_devastator")

#pragma comment(linker, "/export:weapon_devour=metamod_org.weapon_devour")

#pragma comment(linker, "/export:weapon_disc=metamod_org.weapon_disc")

#pragma comment(linker, "/export:weapon_disclauncher=metamod_org.weapon_disclauncher")

#pragma comment(linker, "/export:weapon_discoballs=metamod_org.weapon_discoballs")

#pragma comment(linker, "/export:weapon_disintegrator=metamod_org.weapon_disintegrator")

#pragma comment(linker, "/export:weapon_displacer=metamod_org.weapon_displacer")

#pragma comment(linker, "/export:weapon_divinewind=metamod_org.weapon_divinewind")

#pragma comment(linker, "/export:weapon_dm4=metamod_org.weapon_dm4")

#pragma comment(linker, "/export:weapon_dml=metamod_org.weapon_dml")

#pragma comment(linker, "/export:weapon_double=metamod_org.weapon_double")

#pragma comment(linker, "/export:weapon_doublemagicmisslespell=metamod_org.weapon_doublemagicmisslespell")

#pragma comment(linker, "/export:weapon_doubleshotgun=metamod_org.weapon_doubleshotgun")

#pragma comment(linker, "/export:weapon_dragonball=metamod_org.weapon_dragonball")

#pragma comment(linker, "/export:weapon_dragonbreathspell=metamod_org.weapon_dragonbreathspell")

#pragma comment(linker, "/export:weapon_dragonspell=metamod_org.weapon_dragonspell")

#pragma comment(linker, "/export:weapon_dragunov=metamod_org.weapon_dragunov")

#pragma comment(linker, "/export:weapon_dsr1=metamod_org.weapon_dsr1")

#pragma comment(linker, "/export:weapon_dualberettas=metamod_org.weapon_dualberettas")

#pragma comment(linker, "/export:weapon_dualscorpion=metamod_org.weapon_dualscorpion")

#pragma comment(linker, "/export:weapon_dummy=metamod_org.weapon_dummy")

#pragma comment(linker, "/export:weapon_dynamite=metamod_org.weapon_dynamite")

#pragma comment(linker, "/export:weapon_dynomite=metamod_org.weapon_dynomite")

#pragma comment(linker, "/export:weapon_eagle=metamod_org.weapon_eagle")

#pragma comment(linker, "/export:weapon_eballblaster=metamod_org.weapon_eballblaster")

#pragma comment(linker, "/export:weapon_egon=metamod_org.weapon_egon")

#pragma comment(linker, "/export:weapon_el_standard=metamod_org.weapon_el_standard")

#pragma comment(linker, "/export:weapon_electro=metamod_org.weapon_electro")

#pragma comment(linker, "/export:weapon_elite=metamod_org.weapon_elite")

#pragma comment(linker, "/export:weapon_emag=metamod_org.weapon_emag")

#pragma comment(linker, "/export:weapon_empcannon=metamod_org.weapon_empcannon")

#pragma comment(linker, "/export:weapon_emsniper=metamod_org.weapon_emsniper")

#pragma comment(linker, "/export:weapon_energy=metamod_org.weapon_energy")

#pragma comment(linker, "/export:weapon_enfield=metamod_org.weapon_enfield")

#pragma comment(linker, "/export:weapon_excal=metamod_org.weapon_excal")

#pragma comment(linker, "/export:weapon_experimental=metamod_org.weapon_experimental")

#pragma comment(linker, "/export:weapon_expgrenade=metamod_org.weapon_expgrenade")

#pragma comment(linker, "/export:weapon_exploder=metamod_org.weapon_exploder")

#pragma comment(linker, "/export:weapon_explogun=metamod_org.weapon_explogun")

#pragma comment(linker, "/export:weapon_eyelaser=metamod_org.weapon_eyelaser")

#pragma comment(linker, "/export:weapon_famas=metamod_org.weapon_famas")

#pragma comment(linker, "/export:weapon_fev=metamod_org.weapon_fev")

#pragma comment(linker, "/export:weapon_fg42=metamod_org.weapon_fg42")

#pragma comment(linker, "/export:weapon_finalflash=metamod_org.weapon_finalflash")

#pragma comment(linker, "/export:weapon_fingerlaser=metamod_org.weapon_fingerlaser")

#pragma comment(linker, "/export:weapon_finishingbuster=metamod_org.weapon_finishingbuster")

#pragma comment(linker, "/export:weapon_fireballspell=metamod_org.weapon_fireballspell")

#pragma comment(linker, "/export:weapon_fishingrod=metamod_org.weapon_fishingrod")

#pragma comment(linker, "/export:weapon_fist=metamod_org.weapon_fist")

#pragma comment(linker, "/export:weapon_fists=metamod_org.weapon_fists")

#pragma comment(linker, "/export:weapon_fiveseven=metamod_org.weapon_fiveseven")

#pragma comment(linker, "/export:weapon_flail=metamod_org.weapon_flail")

#pragma comment(linker, "/export:weapon_flakcannon=metamod_org.weapon_flakcannon")

#pragma comment(linker, "/export:weapon_flame=metamod_org.weapon_flame")

#pragma comment(linker, "/export:weapon_flamegrenade=metamod_org.weapon_flamegrenade")

#pragma comment(linker, "/export:weapon_flamegun=metamod_org.weapon_flamegun")

#pragma comment(linker, "/export:weapon_flamelickspell=metamod_org.weapon_flamelickspell")

#pragma comment(linker, "/export:weapon_flamer=metamod_org.weapon_flamer")

#pragma comment(linker, "/export:weapon_flamethrower=metamod_org.weapon_flamethrower")

#pragma comment(linker, "/export:weapon_flaregun=metamod_org.weapon_flaregun")

#pragma comment(linker, "/export:weapon_flarepistol=metamod_org.weapon_flarepistol")

#pragma comment(linker, "/export:weapon_flashbang=metamod_org.weapon_flashbang")

#pragma comment(linker, "/export:weapon_fleshgrenade=metamod_org.weapon_fleshgrenade")

#pragma comment(linker, "/export:weapon_flintlock=metamod_org.weapon_flintlock")

#pragma comment(linker, "/export:weapon_flute=metamod_org.weapon_flute")

#pragma comment(linker, "/export:weapon_fnfal=metamod_org.weapon_fnfal")

#pragma comment(linker, "/export:weapon_fnp90=metamod_org.weapon_fnp90")

#pragma comment(linker, "/export:weapon_forcespell=metamod_org.weapon_forcespell")

#pragma comment(linker, "/export:weapon_frag=metamod_org.weapon_frag")

#pragma comment(linker, "/export:weapon_fraggrenade=metamod_org.weapon_fraggrenade")

#pragma comment(linker, "/export:weapon_freeze=metamod_org.weapon_freeze")

#pragma comment(linker, "/export:weapon_freezer=metamod_org.weapon_freezer")

#pragma comment(linker, "/export:weapon_freezerayspell=metamod_org.weapon_freezerayspell")

#pragma comment(linker, "/export:weapon_friezadisc=metamod_org.weapon_friezadisc")

#pragma comment(linker, "/export:weapon_froster=metamod_org.weapon_froster")

#pragma comment(linker, "/export:weapon_fusil=metamod_org.weapon_fusil")

#pragma comment(linker, "/export:weapon_g11=metamod_org.weapon_g11")

#pragma comment(linker, "/export:weapon_g36=metamod_org.weapon_g36")

#pragma comment(linker, "/export:weapon_g36c=metamod_org.weapon_g36c")

#pragma comment(linker, "/export:weapon_g36cs=metamod_org.weapon_g36cs")

#pragma comment(linker, "/export:weapon_g36e=metamod_org.weapon_g36e")

#pragma comment(linker, "/export:weapon_g36k=metamod_org.weapon_g36k")

#pragma comment(linker, "/export:weapon_g3a3=metamod_org.weapon_g3a3")

#pragma comment(linker, "/export:weapon_g3sg1=metamod_org.weapon_g3sg1")

#pragma comment(linker, "/export:weapon_ga2uss=metamod_org.weapon_ga2uss")

#pragma comment(linker, "/export:weapon_gacgoa=metamod_org.weapon_gacgoa")

#pragma comment(linker, "/export:weapon_galil=metamod_org.weapon_galil")

#pragma comment(linker, "/export:weapon_gallitgun=metamod_org.weapon_gallitgun")

#pragma comment(linker, "/export:weapon_garand=metamod_org.weapon_garand")

#pragma comment(linker, "/export:weapon_gasgrenade=metamod_org.weapon_gasgrenade")

#pragma comment(linker, "/export:weapon_gatlin=metamod_org.weapon_gatlin")

#pragma comment(linker, "/export:weapon_gatling=metamod_org.weapon_gatling")

#pragma comment(linker, "/export:weapon_gattlinggun=metamod_org.weapon_gattlinggun")

#pragma comment(linker, "/export:weapon_gauss=metamod_org.weapon_gauss")

#pragma comment(linker, "/export:weapon_gausspistol=metamod_org.weapon_gausspistol")

#pragma comment(linker, "/export:weapon_generic=metamod_org.weapon_generic")

#pragma comment(linker, "/export:weapon_genericbeam=metamod_org.weapon_genericbeam")

#pragma comment(linker, "/export:weapon_gerknife=metamod_org.weapon_gerknife")

#pragma comment(linker, "/export:weapon_germanknife=metamod_org.weapon_germanknife")

#pragma comment(linker, "/export:weapon_gewehr=metamod_org.weapon_gewehr")

#pragma comment(linker, "/export:weapon_giantplantspell=metamod_org.weapon_giantplantspell")

#pragma comment(linker, "/export:weapon_glauncher=metamod_org.weapon_glauncher")

#pragma comment(linker, "/export:weapon_glock=metamod_org.weapon_glock")

#pragma comment(linker, "/export:weapon_glock17=metamod_org.weapon_glock17")

#pragma comment(linker, "/export:weapon_glock18=metamod_org.weapon_glock18")

#pragma comment(linker, "/export:weapon_glock_auto=metamod_org.weapon_glock_auto")

#pragma comment(linker, "/export:weapon_glock_auto_a=metamod_org.weapon_glock_auto_a")

#pragma comment(linker, "/export:weapon_glstaff=metamod_org.weapon_glstaff")

#pragma comment(linker, "/export:weapon_gluongun=metamod_org.weapon_gluongun")

#pragma comment(linker, "/export:weapon_goaregen=metamod_org.weapon_goaregen")

#pragma comment(linker, "/export:weapon_goldpp7=metamod_org.weapon_goldpp7")

#pragma comment(linker, "/export:weapon_gps=metamod_org.weapon_gps")

#pragma comment(linker, "/export:weapon_grappin=metamod_org.weapon_grappin")

#pragma comment(linker, "/export:weapon_grapple=metamod_org.weapon_grapple")

#pragma comment(linker, "/export:weapon_grease=metamod_org.weapon_grease")

#pragma comment(linker, "/export:weapon_greasegun=metamod_org.weapon_greasegun")

#pragma comment(linker, "/export:weapon_gren=metamod_org.weapon_gren")

#pragma comment(linker, "/export:weapon_grenade=metamod_org.weapon_grenade")

#pragma comment(linker, "/export:weapon_grenadegun=metamod_org.weapon_grenadegun")

#pragma comment(linker, "/export:weapon_grenadelauncher=metamod_org.weapon_grenadelauncher")

#pragma comment(linker, "/export:weapon_guardian=metamod_org.weapon_guardian")

#pragma comment(linker, "/export:weapon_hache=metamod_org.weapon_hache")

#pragma comment(linker, "/export:weapon_hammer=metamod_org.weapon_hammer")

#pragma comment(linker, "/export:weapon_hand=metamod_org.weapon_hand")

#pragma comment(linker, "/export:weapon_handcannon=metamod_org.weapon_handcannon")

#pragma comment(linker, "/export:weapon_handgrenade=metamod_org.weapon_handgrenade")

#pragma comment(linker, "/export:weapon_handgrenade_ex=metamod_org.weapon_handgrenade_ex")

#pragma comment(linker, "/export:weapon_harpoongun=metamod_org.weapon_harpoongun")

#pragma comment(linker, "/export:weapon_he=metamod_org.weapon_he")

#pragma comment(linker, "/export:weapon_healingspray=metamod_org.weapon_healingspray")

#pragma comment(linker, "/export:weapon_heavymachinegun=metamod_org.weapon_heavymachinegun")

#pragma comment(linker, "/export:weapon_hegrenade=metamod_org.weapon_hegrenade")

#pragma comment(linker, "/export:weapon_helico=metamod_org.weapon_helico")

#pragma comment(linker, "/export:weapon_hk21=metamod_org.weapon_hk21")

#pragma comment(linker, "/export:weapon_hk33=metamod_org.weapon_hk33")

#pragma comment(linker, "/export:weapon_hk33ka2=metamod_org.weapon_hk33ka2")

#pragma comment(linker, "/export:weapon_hkmp5=metamod_org.weapon_hkmp5")

#pragma comment(linker, "/export:weapon_holybsword=metamod_org.weapon_holybsword")

#pragma comment(linker, "/export:weapon_horar1=metamod_org.weapon_horar1")

#pragma comment(linker, "/export:weapon_horar2=metamod_org.weapon_horar2")

#pragma comment(linker, "/export:weapon_horg1=metamod_org.weapon_horg1")

#pragma comment(linker, "/export:weapon_horg2=metamod_org.weapon_horg2")

#pragma comment(linker, "/export:weapon_hormg1=metamod_org.weapon_hormg1")

#pragma comment(linker, "/export:weapon_hormg2=metamod_org.weapon_hormg2")

#pragma comment(linker, "/export:weapon_hornetgun=metamod_org.weapon_hornetgun")

#pragma comment(linker, "/export:weapon_hyperblaster=metamod_org.weapon_hyperblaster")

#pragma comment(linker, "/export:weapon_icepokespell=metamod_org.weapon_icepokespell")

#pragma comment(linker, "/export:weapon_impulse=metamod_org.weapon_impulse")

#pragma comment(linker, "/export:weapon_incendiary=metamod_org.weapon_incendiary")

#pragma comment(linker, "/export:weapon_infector=metamod_org.weapon_infector")

#pragma comment(linker, "/export:weapon_invis=metamod_org.weapon_invis")

#pragma comment(linker, "/export:weapon_islavezap=metamod_org.weapon_islavezap")

#pragma comment(linker, "/export:weapon_ithaca=metamod_org.weapon_ithaca")

#pragma comment(linker, "/export:weapon_jackhammer=metamod_org.weapon_jackhammer")

#pragma comment(linker, "/export:weapon_javelin=metamod_org.weapon_javelin")

#pragma comment(linker, "/export:weapon_jetfist=metamod_org.weapon_jetfist")

#pragma comment(linker, "/export:weapon_jetpack=metamod_org.weapon_jetpack")

#pragma comment(linker, "/export:weapon_jumpjet=metamod_org.weapon_jumpjet")

#pragma comment(linker, "/export:weapon_k43=metamod_org.weapon_k43")

#pragma comment(linker, "/export:weapon_kamakazi=metamod_org.weapon_kamakazi")

#pragma comment(linker, "/export:weapon_kameha=metamod_org.weapon_kameha")

#pragma comment(linker, "/export:weapon_kamehameha=metamod_org.weapon_kamehameha")

#pragma comment(linker, "/export:weapon_kametorpedo=metamod_org.weapon_kametorpedo")

#pragma comment(linker, "/export:weapon_kamikaze=metamod_org.weapon_kamikaze")

#pragma comment(linker, "/export:weapon_kar=metamod_org.weapon_kar")

#pragma comment(linker, "/export:weapon_katana=metamod_org.weapon_katana")

#pragma comment(linker, "/export:weapon_kawauso=metamod_org.weapon_kawauso")

#pragma comment(linker, "/export:weapon_kbar=metamod_org.weapon_kbar")

#pragma comment(linker, "/export:weapon_kf7=metamod_org.weapon_kf7")

#pragma comment(linker, "/export:weapon_kiblast=metamod_org.weapon_kiblast")

#pragma comment(linker, "/export:weapon_killsaw=metamod_org.weapon_killsaw")

#pragma comment(linker, "/export:weapon_kmedkit=metamod_org.weapon_kmedkit")

#pragma comment(linker, "/export:weapon_knife=metamod_org.weapon_knife")

#pragma comment(linker, "/export:weapon_lacrymo=metamod_org.weapon_lacrymo")

#pragma comment(linker, "/export:weapon_lance=metamod_org.weapon_lance")

#pragma comment(linker, "/export:weapon_lanceflamme=metamod_org.weapon_lanceflamme")

#pragma comment(linker, "/export:weapon_larve=metamod_org.weapon_larve")

#pragma comment(linker, "/export:weapon_laser=metamod_org.weapon_laser")

#pragma comment(linker, "/export:weapon_laser_rifle=metamod_org.weapon_laser_rifle")

#pragma comment(linker, "/export:weapon_lasergatling=metamod_org.weapon_lasergatling")

#pragma comment(linker, "/export:weapon_launcher=metamod_org.weapon_launcher")

#pragma comment(linker, "/export:weapon_law=metamod_org.weapon_law")

#pragma comment(linker, "/export:weapon_lawgiver=metamod_org.weapon_lawgiver")

#pragma comment(linker, "/export:weapon_lawrod=metamod_org.weapon_lawrod")

#pragma comment(linker, "/export:weapon_leap=metamod_org.weapon_leap")

#pragma comment(linker, "/export:weapon_levitationspell=metamod_org.weapon_levitationspell")

#pragma comment(linker, "/export:weapon_lflamme=metamod_org.weapon_lflamme")

#pragma comment(linker, "/export:weapon_lgrenades=metamod_org.weapon_lgrenades")

#pragma comment(linker, "/export:weapon_lightning=metamod_org.weapon_lightning")

#pragma comment(linker, "/export:weapon_lightningboltspell=metamod_org.weapon_lightningboltspell")

#pragma comment(linker, "/export:weapon_lightningcloudspell=metamod_org.weapon_lightningcloudspell")

#pragma comment(linker, "/export:weapon_lightsaber=metamod_org.weapon_lightsaber")

#pragma comment(linker, "/export:weapon_lightsabre=metamod_org.weapon_lightsabre")

#pragma comment(linker, "/export:weapon_lngun=metamod_org.weapon_lngun")

#pragma comment(linker, "/export:weapon_longbow=metamod_org.weapon_longbow")

#pragma comment(linker, "/export:weapon_longslide=metamod_org.weapon_longslide")

#pragma comment(linker, "/export:weapon_longsword=metamod_org.weapon_longsword")

#pragma comment(linker, "/export:weapon_lr300=metamod_org.weapon_lr300")

#pragma comment(linker, "/export:weapon_lr300s=metamod_org.weapon_lr300s")

#pragma comment(linker, "/export:weapon_lrifle=metamod_org.weapon_lrifle")

#pragma comment(linker, "/export:weapon_luger=metamod_org.weapon_luger")

#pragma comment(linker, "/export:weapon_m11=metamod_org.weapon_m11")

#pragma comment(linker, "/export:weapon_m11sd=metamod_org.weapon_m11sd")

#pragma comment(linker, "/export:weapon_m134=metamod_org.weapon_m134")

#pragma comment(linker, "/export:weapon_m14=metamod_org.weapon_m14")

#pragma comment(linker, "/export:weapon_m16=metamod_org.weapon_m16")

#pragma comment(linker, "/export:weapon_m16a2=metamod_org.weapon_m16a2")

#pragma comment(linker, "/export:weapon_m1carbine=metamod_org.weapon_m1carbine")

#pragma comment(linker, "/export:weapon_m2=metamod_org.weapon_m2")

#pragma comment(linker, "/export:weapon_m21=metamod_org.weapon_m21")

#pragma comment(linker, "/export:weapon_m249=metamod_org.weapon_m249")

#pragma comment(linker, "/export:weapon_m3=metamod_org.weapon_m3")

#pragma comment(linker, "/export:weapon_m4=metamod_org.weapon_m4")

#pragma comment(linker, "/export:weapon_m40a1=metamod_org.weapon_m40a1")

#pragma comment(linker, "/export:weapon_m41=metamod_org.weapon_m41")

#pragma comment(linker, "/export:weapon_m4a1=metamod_org.weapon_m4a1")

#pragma comment(linker, "/export:weapon_m60=metamod_org.weapon_m60")

#pragma comment(linker, "/export:weapon_m61frag=metamod_org.weapon_m61frag")

#pragma comment(linker, "/export:weapon_m67=metamod_org.weapon_m67")

#pragma comment(linker, "/export:weapon_m72=metamod_org.weapon_m72")

#pragma comment(linker, "/export:weapon_m76=metamod_org.weapon_m76")

#pragma comment(linker, "/export:weapon_m79=metamod_org.weapon_m79")

#pragma comment(linker, "/export:weapon_m82=metamod_org.weapon_m82")

#pragma comment(linker, "/export:weapon_m86=metamod_org.weapon_m86")

#pragma comment(linker, "/export:weapon_m92s=metamod_org.weapon_m92s")

#pragma comment(linker, "/export:weapon_m96=metamod_org.weapon_m96")

#pragma comment(linker, "/export:weapon_m98=metamod_org.weapon_m98")

#pragma comment(linker, "/export:weapon_mac=metamod_org.weapon_mac")

#pragma comment(linker, "/export:weapon_mac10=metamod_org.weapon_mac10")

#pragma comment(linker, "/export:weapon_mace=metamod_org.weapon_mace")

#pragma comment(linker, "/export:weapon_machete=metamod_org.weapon_machete")

#pragma comment(linker, "/export:weapon_machinegun=metamod_org.weapon_machinegun")

#pragma comment(linker, "/export:weapon_mag=metamod_org.weapon_mag")

#pragma comment(linker, "/export:weapon_magicmisslespell=metamod_org.weapon_magicmisslespell")

#pragma comment(linker, "/export:weapon_main=metamod_org.weapon_main")

#pragma comment(linker, "/export:weapon_markmusket=metamod_org.weapon_markmusket")

#pragma comment(linker, "/export:weapon_masenko=metamod_org.weapon_masenko")

#pragma comment(linker, "/export:weapon_mat49=metamod_org.weapon_mat49")

#pragma comment(linker, "/export:weapon_match=metamod_org.weapon_match")

#pragma comment(linker, "/export:weapon_matrix=metamod_org.weapon_matrix")

#pragma comment(linker, "/export:weapon_maverick=metamod_org.weapon_maverick")

#pragma comment(linker, "/export:weapon_mc51=metamod_org.weapon_mc51")

#pragma comment(linker, "/export:weapon_medic=metamod_org.weapon_medic")

#pragma comment(linker, "/export:weapon_medikit=metamod_org.weapon_medikit")

#pragma comment(linker, "/export:weapon_medkit=metamod_org.weapon_medkit")

#pragma comment(linker, "/export:weapon_melee=metamod_org.weapon_melee")

#pragma comment(linker, "/export:weapon_metabolize=metamod_org.weapon_metabolize")

#pragma comment(linker, "/export:weapon_meteorspell=metamod_org.weapon_meteorspell")

#pragma comment(linker, "/export:weapon_mf2=metamod_org.weapon_mf2")

#pragma comment(linker, "/export:weapon_mg34=metamod_org.weapon_mg34")

#pragma comment(linker, "/export:weapon_mg36=metamod_org.weapon_mg36")

#pragma comment(linker, "/export:weapon_mg42=metamod_org.weapon_mg42")

#pragma comment(linker, "/export:weapon_microuzi=metamod_org.weapon_microuzi")

#pragma comment(linker, "/export:weapon_microuzi_a=metamod_org.weapon_microuzi_a")

#pragma comment(linker, "/export:weapon_mindmisslespell=metamod_org.weapon_mindmisslespell")

#pragma comment(linker, "/export:weapon_mindray=metamod_org.weapon_mindray")

#pragma comment(linker, "/export:weapon_mine=metamod_org.weapon_mine")

#pragma comment(linker, "/export:weapon_minicanon=metamod_org.weapon_minicanon")

#pragma comment(linker, "/export:weapon_minigun=metamod_org.weapon_minigun")

#pragma comment(linker, "/export:weapon_mk23=metamod_org.weapon_mk23")

#pragma comment(linker, "/export:weapon_model98=metamod_org.weapon_model98")

#pragma comment(linker, "/export:weapon_molotov=metamod_org.weapon_molotov")

#pragma comment(linker, "/export:weapon_molotov_cocktail=metamod_org.weapon_molotov_cocktail")

#pragma comment(linker, "/export:weapon_mop=metamod_org.weapon_mop")

#pragma comment(linker, "/export:weapon_mortar=metamod_org.weapon_mortar")

#pragma comment(linker, "/export:weapon_mortier=metamod_org.weapon_mortier")

#pragma comment(linker, "/export:weapon_morve=metamod_org.weapon_morve")

#pragma comment(linker, "/export:weapon_mosin=metamod_org.weapon_mosin")

#pragma comment(linker, "/export:weapon_mossberg=metamod_org.weapon_mossberg")

#pragma comment(linker, "/export:weapon_mouthblast=metamod_org.weapon_mouthblast")

#pragma comment(linker, "/export:weapon_mouton=metamod_org.weapon_mouton")

#pragma comment(linker, "/export:weapon_mp40=metamod_org.weapon_mp40")

#pragma comment(linker, "/export:weapon_mp44=metamod_org.weapon_mp44")

#pragma comment(linker, "/export:weapon_mp5=metamod_org.weapon_mp5")

#pragma comment(linker, "/export:weapon_mp510=metamod_org.weapon_mp510")

#pragma comment(linker, "/export:weapon_mp5a2=metamod_org.weapon_mp5a2")

#pragma comment(linker, "/export:weapon_mp5a4=metamod_org.weapon_mp5a4")

#pragma comment(linker, "/export:weapon_mp5a5=metamod_org.weapon_mp5a5")

#pragma comment(linker, "/export:weapon_mp5k=metamod_org.weapon_mp5k")

#pragma comment(linker, "/export:weapon_mp5ktac=metamod_org.weapon_mp5ktac")

#pragma comment(linker, "/export:weapon_mp5navy=metamod_org.weapon_mp5navy")

#pragma comment(linker, "/export:weapon_mp5pdw=metamod_org.weapon_mp5pdw")

#pragma comment(linker, "/export:weapon_mp5sd=metamod_org.weapon_mp5sd")

#pragma comment(linker, "/export:weapon_mp5sd5=metamod_org.weapon_mp5sd5")

#pragma comment(linker, "/export:weapon_msg90=metamod_org.weapon_msg90")

#pragma comment(linker, "/export:weapon_musket=metamod_org.weapon_musket")

#pragma comment(linker, "/export:weapon_musketoon=metamod_org.weapon_musketoon")

#pragma comment(linker, "/export:weapon_mustardgrenade=metamod_org.weapon_mustardgrenade")

#pragma comment(linker, "/export:weapon_mwgun=metamod_org.weapon_mwgun")

#pragma comment(linker, "/export:weapon_nailgun=metamod_org.weapon_nailgun")

#pragma comment(linker, "/export:weapon_napalm=metamod_org.weapon_napalm")

#pragma comment(linker, "/export:weapon_narcogrenade=metamod_org.weapon_narcogrenade")

#pragma comment(linker, "/export:weapon_ndagger=metamod_org.weapon_ndagger")

#pragma comment(linker, "/export:weapon_needle=metamod_org.weapon_needle")

#pragma comment(linker, "/export:weapon_nervegrenade=metamod_org.weapon_nervegrenade")

#pragma comment(linker, "/export:weapon_ngun=metamod_org.weapon_ngun")

#pragma comment(linker, "/export:weapon_nightstick=metamod_org.weapon_nightstick")

#pragma comment(linker, "/export:weapon_not_in_use_grenade=metamod_org.weapon_not_in_use_grenade")

#pragma comment(linker, "/export:weapon_nukegun=metamod_org.weapon_nukegun")

#pragma comment(linker, "/export:weapon_nuker=metamod_org.weapon_nuker")

#pragma comment(linker, "/export:weapon_null=metamod_org.weapon_null")

#pragma comment(linker, "/export:weapon_nva_grenade=metamod_org.weapon_nva_grenade")

#pragma comment(linker, "/export:weapon_oicw=metamod_org.weapon_oicw")

#pragma comment(linker, "/export:weapon_omen=metamod_org.weapon_omen")

#pragma comment(linker, "/export:weapon_orbital=metamod_org.weapon_orbital")

#pragma comment(linker, "/export:weapon_orracle=metamod_org.weapon_orracle")

#pragma comment(linker, "/export:weapon_p225=metamod_org.weapon_p225")

#pragma comment(linker, "/export:weapon_p226=metamod_org.weapon_p226")

#pragma comment(linker, "/export:weapon_p226mp=metamod_org.weapon_p226mp")

#pragma comment(linker, "/export:weapon_p228=metamod_org.weapon_p228")

#pragma comment(linker, "/export:weapon_p90=metamod_org.weapon_p90")

#pragma comment(linker, "/export:weapon_p99=metamod_org.weapon_p99")

#pragma comment(linker, "/export:weapon_paintball=metamod_org.weapon_paintball")

#pragma comment(linker, "/export:weapon_paintgrenade=metamod_org.weapon_paintgrenade")

#pragma comment(linker, "/export:weapon_paralysis=metamod_org.weapon_paralysis")

#pragma comment(linker, "/export:weapon_parasite=metamod_org.weapon_parasite")

#pragma comment(linker, "/export:weapon_parrot=metamod_org.weapon_parrot")

#pragma comment(linker, "/export:weapon_pdw=metamod_org.weapon_pdw")

#pragma comment(linker, "/export:weapon_penguin=metamod_org.weapon_penguin")

#pragma comment(linker, "/export:weapon_pgp=metamod_org.weapon_pgp")

#pragma comment(linker, "/export:weapon_phantom=metamod_org.weapon_phantom")

#pragma comment(linker, "/export:weapon_phoenix=metamod_org.weapon_phoenix")

#pragma comment(linker, "/export:weapon_photongun=metamod_org.weapon_photongun")

#pragma comment(linker, "/export:weapon_piat=metamod_org.weapon_piat")

#pragma comment(linker, "/export:weapon_pick=metamod_org.weapon_pick")

#pragma comment(linker, "/export:weapon_pigeon=metamod_org.weapon_pigeon")

#pragma comment(linker, "/export:weapon_pipebomb=metamod_org.weapon_pipebomb")

#pragma comment(linker, "/export:weapon_pipewrench=metamod_org.weapon_pipewrench")

#pragma comment(linker, "/export:weapon_pistol=metamod_org.weapon_pistol")

#pragma comment(linker, "/export:weapon_pistolet=metamod_org.weapon_pistolet")

#pragma comment(linker, "/export:weapon_pkm=metamod_org.weapon_pkm")

#pragma comment(linker, "/export:weapon_plasma=metamod_org.weapon_plasma")

#pragma comment(linker, "/export:weapon_plasmarifle=metamod_org.weapon_plasmarifle")

#pragma comment(linker, "/export:weapon_plauncher=metamod_org.weapon_plauncher")

#pragma comment(linker, "/export:weapon_pmine=metamod_org.weapon_pmine")

#pragma comment(linker, "/export:weapon_poison=metamod_org.weapon_poison")

#pragma comment(linker, "/export:weapon_poolstick=metamod_org.weapon_poolstick")

#pragma comment(linker, "/export:weapon_powderkeg=metamod_org.weapon_powderkeg")

#pragma comment(linker, "/export:weapon_powerbeam=metamod_org.weapon_powerbeam")

#pragma comment(linker, "/export:weapon_powerblade=metamod_org.weapon_powerblade")

#pragma comment(linker, "/export:weapon_prifle=metamod_org.weapon_prifle")

#pragma comment(linker, "/export:weapon_primalscream=metamod_org.weapon_primalscream")

#pragma comment(linker, "/export:weapon_proximity=metamod_org.weapon_proximity")

#pragma comment(linker, "/export:weapon_pschreck=metamod_org.weapon_pschreck")

#pragma comment(linker, "/export:weapon_psg=metamod_org.weapon_psg")

#pragma comment(linker, "/export:weapon_psg1=metamod_org.weapon_psg1")

#pragma comment(linker, "/export:weapon_pt=metamod_org.weapon_pt")

#pragma comment(linker, "/export:weapon_pulserifle=metamod_org.weapon_pulserifle")

#pragma comment(linker, "/export:weapon_pushhands=metamod_org.weapon_pushhands")

#pragma comment(linker, "/export:weapon_python=metamod_org.weapon_python")

#pragma comment(linker, "/export:weapon_quakegun=metamod_org.weapon_quakegun")

#pragma comment(linker, "/export:weapon_radio=metamod_org.weapon_radio")

#pragma comment(linker, "/export:weapon_railgun=metamod_org.weapon_railgun")

#pragma comment(linker, "/export:weapon_ralkek=metamod_org.weapon_ralkek")

#pragma comment(linker, "/export:weapon_rallyhp=metamod_org.weapon_rallyhp")

#pragma comment(linker, "/export:weapon_rbull=metamod_org.weapon_rbull")

#pragma comment(linker, "/export:weapon_rcp90=metamod_org.weapon_rcp90")

#pragma comment(linker, "/export:weapon_redeemer=metamod_org.weapon_redeemer")

#pragma comment(linker, "/export:weapon_reetou=metamod_org.weapon_reetou")

#pragma comment(linker, "/export:weapon_regeneration=metamod_org.weapon_regeneration")

#pragma comment(linker, "/export:weapon_rem1100=metamod_org.weapon_rem1100")

#pragma comment(linker, "/export:weapon_remington=metamod_org.weapon_remington")

#pragma comment(linker, "/export:weapon_renzoku=metamod_org.weapon_renzoku")

#pragma comment(linker, "/export:weapon_resource=metamod_org.weapon_resource")

#pragma comment(linker, "/export:weapon_rgd5=metamod_org.weapon_rgd5")

#pragma comment(linker, "/export:weapon_rifle=metamod_org.weapon_rifle")

#pragma comment(linker, "/export:weapon_rmine=metamod_org.weapon_rmine")

#pragma comment(linker, "/export:weapon_rocketlauncher=metamod_org.weapon_rocketlauncher")

#pragma comment(linker, "/export:weapon_rocketpistol=metamod_org.weapon_rocketpistol")

#pragma comment(linker, "/export:weapon_rollingstonespell=metamod_org.weapon_rollingstonespell")

#pragma comment(linker, "/export:weapon_rpd=metamod_org.weapon_rpd")

#pragma comment(linker, "/export:weapon_rpg=metamod_org.weapon_rpg")

#pragma comment(linker, "/export:weapon_rpg7=metamod_org.weapon_rpg7")

#pragma comment(linker, "/export:weapon_rs202m2=metamod_org.weapon_rs202m2")

#pragma comment(linker, "/export:weapon_rs_meta=metamod_org.weapon_rs_meta")

#pragma comment(linker, "/export:weapon_ruche=metamod_org.weapon_ruche")

#pragma comment(linker, "/export:weapon_ruger=metamod_org.weapon_ruger")

#pragma comment(linker, "/export:weapon_rumgun=metamod_org.weapon_rumgun")

#pragma comment(linker, "/export:weapon_runner=metamod_org.weapon_runner")

#pragma comment(linker, "/export:weapon_sa80=metamod_org.weapon_sa80")

#pragma comment(linker, "/export:weapon_saa=metamod_org.weapon_saa")

#pragma comment(linker, "/export:weapon_saber=metamod_org.weapon_saber")

#pragma comment(linker, "/export:weapon_sabers=metamod_org.weapon_sabers")

#pragma comment(linker, "/export:weapon_saiga=metamod_org.weapon_saiga")

#pragma comment(linker, "/export:weapon_sainte=metamod_org.weapon_sainte")

#pragma comment(linker, "/export:weapon_sako=metamod_org.weapon_sako")

#pragma comment(linker, "/export:weapon_satchel=metamod_org.weapon_satchel")

#pragma comment(linker, "/export:weapon_satelitelaser=metamod_org.weapon_satelitelaser")

#pragma comment(linker, "/export:weapon_satellite=metamod_org.weapon_satellite")

#pragma comment(linker, "/export:weapon_sawed=metamod_org.weapon_sawed")

#pragma comment(linker, "/export:weapon_sawedoff=metamod_org.weapon_sawedoff")

#pragma comment(linker, "/export:weapon_sawgun=metamod_org.weapon_sawgun")

#pragma comment(linker, "/export:weapon_sbarrel=metamod_org.weapon_sbarrel")

#pragma comment(linker, "/export:weapon_scatterbeam=metamod_org.weapon_scatterbeam")

#pragma comment(linker, "/export:weapon_scattergun=metamod_org.weapon_scattergun")

#pragma comment(linker, "/export:weapon_scattershot=metamod_org.weapon_scattershot")

#pragma comment(linker, "/export:weapon_scopedenfield=metamod_org.weapon_scopedenfield")

#pragma comment(linker, "/export:weapon_scopedfg42=metamod_org.weapon_scopedfg42")

#pragma comment(linker, "/export:weapon_scopedkar=metamod_org.weapon_scopedkar")

#pragma comment(linker, "/export:weapon_scorpion=metamod_org.weapon_scorpion")

#pragma comment(linker, "/export:weapon_scout=metamod_org.weapon_scout")

#pragma comment(linker, "/export:weapon_seburo=metamod_org.weapon_seburo")

#pragma comment(linker, "/export:weapon_sensu=metamod_org.weapon_sensu")

#pragma comment(linker, "/export:weapon_seringue=metamod_org.weapon_seringue")

#pragma comment(linker, "/export:weapon_sg550=metamod_org.weapon_sg550")

#pragma comment(linker, "/export:weapon_sg552=metamod_org.weapon_sg552")

#pragma comment(linker, "/export:weapon_sgenerator=metamod_org.weapon_sgenerator")

#pragma comment(linker, "/export:weapon_shield=metamod_org.weapon_shield")

#pragma comment(linker, "/export:weapon_shieldattack=metamod_org.weapon_shieldattack")

#pragma comment(linker, "/export:weapon_shieldgun=metamod_org.weapon_shieldgun")

#pragma comment(linker, "/export:weapon_shieldspell=metamod_org.weapon_shieldspell")

#pragma comment(linker, "/export:weapon_shocker=metamod_org.weapon_shocker")

#pragma comment(linker, "/export:weapon_shocker2k=metamod_org.weapon_shocker2k")

#pragma comment(linker, "/export:weapon_shockrifle=metamod_org.weapon_shockrifle")

#pragma comment(linker, "/export:weapon_shockroach=metamod_org.weapon_shockroach")

#pragma comment(linker, "/export:weapon_shotgun=metamod_org.weapon_shotgun")

#pragma comment(linker, "/export:weapon_shrinker=metamod_org.weapon_shrinker")

#pragma comment(linker, "/export:weapon_sig=metamod_org.weapon_sig")

#pragma comment(linker, "/export:weapon_sig245=metamod_org.weapon_sig245")

#pragma comment(linker, "/export:weapon_sig550=metamod_org.weapon_sig550")

#pragma comment(linker, "/export:weapon_sigpro=metamod_org.weapon_sigpro")

#pragma comment(linker, "/export:weapon_silverpp7=metamod_org.weapon_silverpp7")

#pragma comment(linker, "/export:weapon_sixshooter=metamod_org.weapon_sixshooter")

#pragma comment(linker, "/export:weapon_skeletonspell=metamod_org.weapon_skeletonspell")

#pragma comment(linker, "/export:weapon_sks=metamod_org.weapon_sks")

#pragma comment(linker, "/export:weapon_skullspell=metamod_org.weapon_skullspell")

#pragma comment(linker, "/export:weapon_skunk=metamod_org.weapon_skunk")

#pragma comment(linker, "/export:weapon_sl68=metamod_org.weapon_sl68")

#pragma comment(linker, "/export:weapon_slappers=metamod_org.weapon_slappers")

#pragma comment(linker, "/export:weapon_sledge=metamod_org.weapon_sledge")

#pragma comment(linker, "/export:weapon_sledgehammer=metamod_org.weapon_sledgehammer")

#pragma comment(linker, "/export:weapon_sm_assaultcannon=metamod_org.weapon_sm_assaultcannon")

#pragma comment(linker, "/export:weapon_sm_bolter=metamod_org.weapon_sm_bolter")

#pragma comment(linker, "/export:weapon_sm_boltpistol=metamod_org.weapon_sm_boltpistol")

#pragma comment(linker, "/export:weapon_sm_combatknife=metamod_org.weapon_sm_combatknife")

#pragma comment(linker, "/export:weapon_sm_flamer=metamod_org.weapon_sm_flamer")

#pragma comment(linker, "/export:weapon_sm_fraggrenade=metamod_org.weapon_sm_fraggrenade")

#pragma comment(linker, "/export:weapon_sm_heavybolter=metamod_org.weapon_sm_heavybolter")

#pragma comment(linker, "/export:weapon_sm_heavyflamer=metamod_org.weapon_sm_heavyflamer")

#pragma comment(linker, "/export:weapon_sm_lascannon=metamod_org.weapon_sm_lascannon")

#pragma comment(linker, "/export:weapon_sm_missilelauncher=metamod_org.weapon_sm_missilelauncher")

#pragma comment(linker, "/export:weapon_sm_poweraxe=metamod_org.weapon_sm_poweraxe")

#pragma comment(linker, "/export:weapon_sm_powersword=metamod_org.weapon_sm_powersword")

#pragma comment(linker, "/export:weapon_sm_stormbolter=metamod_org.weapon_sm_stormbolter")

#pragma comment(linker, "/export:weapon_smartgun=metamod_org.weapon_smartgun")

#pragma comment(linker, "/export:weapon_smaw=metamod_org.weapon_smaw")

#pragma comment(linker, "/export:weapon_smg9=metamod_org.weapon_smg9")

#pragma comment(linker, "/export:weapon_smkgrenade=metamod_org.weapon_smkgrenade")

#pragma comment(linker, "/export:weapon_smoke=metamod_org.weapon_smoke")

#pragma comment(linker, "/export:weapon_smokegrenade=metamod_org.weapon_smokegrenade")

#pragma comment(linker, "/export:weapon_snUZI=metamod_org.weapon_snUZI")

#pragma comment(linker, "/export:weapon_snark=metamod_org.weapon_snark")

#pragma comment(linker, "/export:weapon_snipe=metamod_org.weapon_snipe")

#pragma comment(linker, "/export:weapon_sniper=metamod_org.weapon_sniper")

#pragma comment(linker, "/export:weapon_sniper3=metamod_org.weapon_sniper3")

#pragma comment(linker, "/export:weapon_sniperrifle=metamod_org.weapon_sniperrifle")

#pragma comment(linker, "/export:weapon_snowball=metamod_org.weapon_snowball")

#pragma comment(linker, "/export:weapon_socom=metamod_org.weapon_socom")

#pragma comment(linker, "/export:weapon_socomtac=metamod_org.weapon_socomtac")

#pragma comment(linker, "/export:weapon_solarflare=metamod_org.weapon_solarflare")

#pragma comment(linker, "/export:weapon_soniccannon=metamod_org.weapon_soniccannon")

#pragma comment(linker, "/export:weapon_sonicgrenade=metamod_org.weapon_sonicgrenade")

#pragma comment(linker, "/export:weapon_spade=metamod_org.weapon_spade")

#pragma comment(linker, "/export:weapon_spas=metamod_org.weapon_spas")

#pragma comment(linker, "/export:weapon_spas12=metamod_org.weapon_spas12")

#pragma comment(linker, "/export:weapon_spear=metamod_org.weapon_spear")

#pragma comment(linker, "/export:weapon_specialbeamcannon=metamod_org.weapon_specialbeamcannon")

#pragma comment(linker, "/export:weapon_spectre=metamod_org.weapon_spectre")

#pragma comment(linker, "/export:weapon_spider=metamod_org.weapon_spider")

#pragma comment(linker, "/export:weapon_spiderbomb=metamod_org.weapon_spiderbomb")

#pragma comment(linker, "/export:weapon_spikegun=metamod_org.weapon_spikegun")

#pragma comment(linker, "/export:weapon_spiritbomb=metamod_org.weapon_spiritbomb")

#pragma comment(linker, "/export:weapon_spiritwizspell=metamod_org.weapon_spiritwizspell")

#pragma comment(linker, "/export:weapon_spit=metamod_org.weapon_spit")

#pragma comment(linker, "/export:weapon_spitcarbine=metamod_org.weapon_spitcarbine")

#pragma comment(linker, "/export:weapon_spitpistol=metamod_org.weapon_spitpistol")

#pragma comment(linker, "/export:weapon_spore=metamod_org.weapon_spore")

#pragma comment(linker, "/export:weapon_sporelauncher=metamod_org.weapon_sporelauncher")

#pragma comment(linker, "/export:weapon_spotboltspell=metamod_org.weapon_spotboltspell")

#pragma comment(linker, "/export:weapon_spring=metamod_org.weapon_spring")

#pragma comment(linker, "/export:weapon_spy=metamod_org.weapon_spy")

#pragma comment(linker, "/export:weapon_spycam=metamod_org.weapon_spycam")

#pragma comment(linker, "/export:weapon_spyder=metamod_org.weapon_spyder")

#pragma comment(linker, "/export:weapon_srifle=metamod_org.weapon_srifle")

#pragma comment(linker, "/export:weapon_ssg3000=metamod_org.weapon_ssg3000")

#pragma comment(linker, "/export:weapon_sshotgun=metamod_org.weapon_sshotgun")

#pragma comment(linker, "/export:weapon_st_far=metamod_org.weapon_st_far")

#pragma comment(linker, "/export:weapon_st_heavy=metamod_org.weapon_st_heavy")

#pragma comment(linker, "/export:weapon_st_medium=metamod_org.weapon_st_medium")

#pragma comment(linker, "/export:weapon_st_melee=metamod_org.weapon_st_melee")

#pragma comment(linker, "/export:weapon_st_power=metamod_org.weapon_st_power")

#pragma comment(linker, "/export:weapon_st_psi=metamod_org.weapon_st_psi")

#pragma comment(linker, "/export:weapon_st_short=metamod_org.weapon_st_short")

#pragma comment(linker, "/export:weapon_st_special=metamod_org.weapon_st_special")

#pragma comment(linker, "/export:weapon_st_throw=metamod_org.weapon_st_throw")

#pragma comment(linker, "/export:weapon_staff=metamod_org.weapon_staff")

#pragma comment(linker, "/export:weapon_star=metamod_org.weapon_star")

#pragma comment(linker, "/export:weapon_sten=metamod_org.weapon_sten")

#pragma comment(linker, "/export:weapon_sterling=metamod_org.weapon_sterling")

#pragma comment(linker, "/export:weapon_steyr_m40=metamod_org.weapon_steyr_m40")

#pragma comment(linker, "/export:weapon_stg24=metamod_org.weapon_stg24")

#pragma comment(linker, "/export:weapon_stickgrenade=metamod_org.weapon_stickgrenade")

#pragma comment(linker, "/export:weapon_stickgrenade_ex=metamod_org.weapon_stickgrenade_ex")

#pragma comment(linker, "/export:weapon_stinger=metamod_org.weapon_stinger")

#pragma comment(linker, "/export:weapon_stingray2=metamod_org.weapon_stingray2")

#pragma comment(linker, "/export:weapon_stomp=metamod_org.weapon_stomp")

#pragma comment(linker, "/export:weapon_stoner=metamod_org.weapon_stoner")

#pragma comment(linker, "/export:weapon_stonerscope=metamod_org.weapon_stonerscope")

#pragma comment(linker, "/export:weapon_stonersilencer=metamod_org.weapon_stonersilencer")

#pragma comment(linker, "/export:weapon_stubgun=metamod_org.weapon_stubgun")

#pragma comment(linker, "/export:weapon_stumpgun=metamod_org.weapon_stumpgun")

#pragma comment(linker, "/export:weapon_stupid=metamod_org.weapon_stupid")

#pragma comment(linker, "/export:weapon_super_mouton=metamod_org.weapon_super_mouton")

#pragma comment(linker, "/export:weapon_supernailgun=metamod_org.weapon_supernailgun")

#pragma comment(linker, "/export:weapon_supershotgun=metamod_org.weapon_supershotgun")

#pragma comment(linker, "/export:weapon_svd=metamod_org.weapon_svd")

#pragma comment(linker, "/export:weapon_swarm_gargflame=metamod_org.weapon_swarm_gargflame")

#pragma comment(linker, "/export:weapon_swipe=metamod_org.weapon_swipe")

#pragma comment(linker, "/export:weapon_sword=metamod_org.weapon_sword")

#pragma comment(linker, "/export:weapon_syringe=metamod_org.weapon_syringe")

#pragma comment(linker, "/export:weapon_tacgun=metamod_org.weapon_tacgun")

#pragma comment(linker, "/export:weapon_taucannon=metamod_org.weapon_taucannon")

#pragma comment(linker, "/export:weapon_tavor=metamod_org.weapon_tavor")

#pragma comment(linker, "/export:weapon_tdagger=metamod_org.weapon_tdagger")

#pragma comment(linker, "/export:weapon_tec9=metamod_org.weapon_tec9")

#pragma comment(linker, "/export:weapon_telekinesis=metamod_org.weapon_telekinesis")

#pragma comment(linker, "/export:weapon_teleporter=metamod_org.weapon_teleporter")

#pragma comment(linker, "/export:weapon_teleporteur=metamod_org.weapon_teleporteur")

#pragma comment(linker, "/export:weapon_teslagun=metamod_org.weapon_teslagun")

#pragma comment(linker, "/export:weapon_thompson=metamod_org.weapon_thompson")

#pragma comment(linker, "/export:weapon_thornblastspell=metamod_org.weapon_thornblastspell")

#pragma comment(linker, "/export:weapon_throwaxe=metamod_org.weapon_throwaxe")

#pragma comment(linker, "/export:weapon_throwing_knife=metamod_org.weapon_throwing_knife")

#pragma comment(linker, "/export:weapon_throwingknife=metamod_org.weapon_throwingknife")

#pragma comment(linker, "/export:weapon_timmy=metamod_org.weapon_timmy")

#pragma comment(linker, "/export:weapon_tknife=metamod_org.weapon_tknife")

#pragma comment(linker, "/export:weapon_tmine=metamod_org.weapon_tmine")

#pragma comment(linker, "/export:weapon_tmp=metamod_org.weapon_tmp")

#pragma comment(linker, "/export:weapon_tnt=metamod_org.weapon_tnt")

#pragma comment(linker, "/export:weapon_toad=metamod_org.weapon_toad")

#pragma comment(linker, "/export:weapon_tokarev=metamod_org.weapon_tokarev")

#pragma comment(linker, "/export:weapon_tomahawk=metamod_org.weapon_tomahawk")

#pragma comment(linker, "/export:weapon_tommy=metamod_org.weapon_tommy")

#pragma comment(linker, "/export:weapon_tommygun=metamod_org.weapon_tommygun")

#pragma comment(linker, "/export:weapon_tornadospell=metamod_org.weapon_tornadospell")

#pragma comment(linker, "/export:weapon_transistor=metamod_org.weapon_transistor")

#pragma comment(linker, "/export:weapon_translocator=metamod_org.weapon_translocator")

#pragma comment(linker, "/export:weapon_treasure=metamod_org.weapon_treasure")

#pragma comment(linker, "/export:weapon_trident=metamod_org.weapon_trident")

#pragma comment(linker, "/export:weapon_trigun=metamod_org.weapon_trigun")

#pragma comment(linker, "/export:weapon_triplaser=metamod_org.weapon_triplaser")

#pragma comment(linker, "/export:weapon_tripmine=metamod_org.weapon_tripmine")

#pragma comment(linker, "/export:weapon_trooper=metamod_org.weapon_trooper")

#pragma comment(linker, "/export:weapon_tsgun=metamod_org.weapon_tsgun")

#pragma comment(linker, "/export:weapon_tucan=metamod_org.weapon_tucan")

#pragma comment(linker, "/export:weapon_turret=metamod_org.weapon_turret")

#pragma comment(linker, "/export:weapon_twosword=metamod_org.weapon_twosword")

#pragma comment(linker, "/export:weapon_u2=metamod_org.weapon_u2")

#pragma comment(linker, "/export:weapon_umbra=metamod_org.weapon_umbra")

#pragma comment(linker, "/export:weapon_umbrella=metamod_org.weapon_umbrella")

#pragma comment(linker, "/export:weapon_ump45=metamod_org.weapon_ump45")

#pragma comment(linker, "/export:weapon_updraftspell=metamod_org.weapon_updraftspell")

#pragma comment(linker, "/export:weapon_us_grenade=metamod_org.weapon_us_grenade")

#pragma comment(linker, "/export:weapon_usas=metamod_org.weapon_usas")

#pragma comment(linker, "/export:weapon_usas12=metamod_org.weapon_usas12")

#pragma comment(linker, "/export:weapon_usp=metamod_org.weapon_usp")

#pragma comment(linker, "/export:weapon_uspmp=metamod_org.weapon_uspmp")

#pragma comment(linker, "/export:weapon_uzi=metamod_org.weapon_uzi")

#pragma comment(linker, "/export:weapon_uziakimbo=metamod_org.weapon_uziakimbo")

#pragma comment(linker, "/export:weapon_vepr=metamod_org.weapon_vepr")

#pragma comment(linker, "/export:weapon_viksword=metamod_org.weapon_viksword")

#pragma comment(linker, "/export:weapon_vomit=metamod_org.weapon_vomit")

#pragma comment(linker, "/export:weapon_vsbike=metamod_org.weapon_vsbike")

#pragma comment(linker, "/export:weapon_vsclaw=metamod_org.weapon_vsclaw")

#pragma comment(linker, "/export:weapon_vscolt=metamod_org.weapon_vscolt")

#pragma comment(linker, "/export:weapon_vscrossbow=metamod_org.weapon_vscrossbow")

#pragma comment(linker, "/export:weapon_vscue=metamod_org.weapon_vscue")

#pragma comment(linker, "/export:weapon_vsdbshotgun=metamod_org.weapon_vsdbshotgun")

#pragma comment(linker, "/export:weapon_vsmp5=metamod_org.weapon_vsmp5")

#pragma comment(linker, "/export:weapon_vsshotgun=metamod_org.weapon_vsshotgun")

#pragma comment(linker, "/export:weapon_vsstake=metamod_org.weapon_vsstake")

#pragma comment(linker, "/export:weapon_vsthunderfive=metamod_org.weapon_vsthunderfive")

#pragma comment(linker, "/export:weapon_vswinchester=metamod_org.weapon_vswinchester")

#pragma comment(linker, "/export:weapon_vulcan=metamod_org.weapon_vulcan")

#pragma comment(linker, "/export:weapon_wa2000=metamod_org.weapon_wa2000")

#pragma comment(linker, "/export:weapon_warhammer=metamod_org.weapon_warhammer")

#pragma comment(linker, "/export:weapon_webley=metamod_org.weapon_webley")

#pragma comment(linker, "/export:weapon_webspinner=metamod_org.weapon_webspinner")

#pragma comment(linker, "/export:weapon_welder=metamod_org.weapon_welder")

#pragma comment(linker, "/export:weapon_whirlwindspell=metamod_org.weapon_whirlwindspell")

#pragma comment(linker, "/export:weapon_whiskey=metamod_org.weapon_whiskey")

#pragma comment(linker, "/export:weapon_whiterayspell=metamod_org.weapon_whiterayspell")

#pragma comment(linker, "/export:weapon_whl=metamod_org.weapon_whl")

#pragma comment(linker, "/export:weapon_winchester=metamod_org.weapon_winchester")

#pragma comment(linker, "/export:weapon_wombatspell=metamod_org.weapon_wombatspell")

#pragma comment(linker, "/export:weapon_wyvernspell=metamod_org.weapon_wyvernspell")

#pragma comment(linker, "/export:weapon_xbow=metamod_org.weapon_xbow")

#pragma comment(linker, "/export:weapon_xm1014=metamod_org.weapon_xm1014")

#pragma comment(linker, "/export:weapon_xm4=metamod_org.weapon_xm4")

#pragma comment(linker, "/export:weapon_zat=metamod_org.weapon_zat")

#pragma comment(linker, "/export:weapon_zatarc=metamod_org.weapon_zatarc")

#pragma comment(linker, "/export:weapon_zmg=metamod_org.weapon_zmg")

#pragma comment(linker, "/export:weaponbox=metamod_org.weaponbox")

#pragma comment(linker, "/export:weather_genie=metamod_org.weather_genie")

#pragma comment(linker, "/export:weather_litnode=metamod_org.weather_litnode")

#pragma comment(linker, "/export:webgunprojectile=metamod_org.webgunprojectile")

#pragma comment(linker, "/export:wh=metamod_org.wh")

#pragma comment(linker, "/export:wheel=metamod_org.wheel")

#pragma comment(linker, "/export:wheel_ent=metamod_org.wheel_ent")

#pragma comment(linker, "/export:whiskey_whisk=metamod_org.whiskey_whisk")

#pragma comment(linker, "/export:whshard=metamod_org.whshard")

#pragma comment(linker, "/export:world_areacontrol=metamod_org.world_areacontrol")

#pragma comment(linker, "/export:world_artefact=metamod_org.world_artefact")

#pragma comment(linker, "/export:world_capturelocation=metamod_org.world_capturelocation")

#pragma comment(linker, "/export:world_items=metamod_org.world_items")

#pragma comment(linker, "/export:worldspawn=metamod_org.worldspawn")

#pragma comment(linker, "/export:ww_ammo_satchels=metamod_org.ww_ammo_satchels")

#pragma comment(linker, "/export:ww_ammo_spellbook=metamod_org.ww_ammo_spellbook")

#pragma comment(linker, "/export:ww_bearbite=metamod_org.ww_bearbite")

#pragma comment(linker, "/export:ww_emitter=metamod_org.ww_emitter")

#pragma comment(linker, "/export:ww_monstermaker=metamod_org.ww_monstermaker")

#pragma comment(linker, "/export:ww_satchel=metamod_org.ww_satchel")

#pragma comment(linker, "/export:ww_satchel_archmage=metamod_org.ww_satchel_archmage")

#pragma comment(linker, "/export:ww_satchel_death=metamod_org.ww_satchel_death")

#pragma comment(linker, "/export:ww_satchel_dragon=metamod_org.ww_satchel_dragon")

#pragma comment(linker, "/export:ww_satchel_earth=metamod_org.ww_satchel_earth")

#pragma comment(linker, "/export:ww_satchel_fire=metamod_org.ww_satchel_fire")

#pragma comment(linker, "/export:ww_satchel_ice=metamod_org.ww_satchel_ice")

#pragma comment(linker, "/export:ww_satchel_life=metamod_org.ww_satchel_life")

#pragma comment(linker, "/export:ww_satchel_lightning=metamod_org.ww_satchel_lightning")

#pragma comment(linker, "/export:ww_satchel_nature=metamod_org.ww_satchel_nature")

#pragma comment(linker, "/export:ww_satchel_wind=metamod_org.ww_satchel_wind")

#pragma comment(linker, "/export:ww_seal=metamod_org.ww_seal")

#pragma comment(linker, "/export:ww_seal_death=metamod_org.ww_seal_death")

#pragma comment(linker, "/export:ww_seal_dragon=metamod_org.ww_seal_dragon")

#pragma comment(linker, "/export:ww_seal_earth=metamod_org.ww_seal_earth")

#pragma comment(linker, "/export:ww_seal_fire=metamod_org.ww_seal_fire")

#pragma comment(linker, "/export:ww_seal_ice=metamod_org.ww_seal_ice")

#pragma comment(linker, "/export:ww_seal_life=metamod_org.ww_seal_life")

#pragma comment(linker, "/export:ww_seal_lightning=metamod_org.ww_seal_lightning")

#pragma comment(linker, "/export:ww_seal_nature=metamod_org.ww_seal_nature")

#pragma comment(linker, "/export:ww_seal_wind=metamod_org.ww_seal_wind")

#pragma comment(linker, "/export:ww_sentrycrystal=metamod_org.ww_sentrycrystal")

#pragma comment(linker, "/export:ww_spell_beanstalk=metamod_org.ww_spell_beanstalk")

#pragma comment(linker, "/export:ww_spell_bird=metamod_org.ww_spell_bird")

#pragma comment(linker, "/export:ww_spell_deathray=metamod_org.ww_spell_deathray")

#pragma comment(linker, "/export:ww_spell_doublemissile=metamod_org.ww_spell_doublemissile")

#pragma comment(linker, "/export:ww_spell_dragonbreath=metamod_org.ww_spell_dragonbreath")

#pragma comment(linker, "/export:ww_spell_fireball=metamod_org.ww_spell_fireball")

#pragma comment(linker, "/export:ww_spell_flamelick=metamod_org.ww_spell_flamelick")

#pragma comment(linker, "/export:ww_spell_forceblast=metamod_org.ww_spell_forceblast")

#pragma comment(linker, "/export:ww_spell_freezeray=metamod_org.ww_spell_freezeray")

#pragma comment(linker, "/export:ww_spell_iceshard=metamod_org.ww_spell_iceshard")

#pragma comment(linker, "/export:ww_spell_levitate=metamod_org.ww_spell_levitate")

#pragma comment(linker, "/export:ww_spell_lightningbolt=metamod_org.ww_spell_lightningbolt")

#pragma comment(linker, "/export:ww_spell_missile=metamod_org.ww_spell_missile")

#pragma comment(linker, "/export:ww_spell_pebbleblast=metamod_org.ww_spell_pebbleblast")

#pragma comment(linker, "/export:ww_spell_seal=metamod_org.ww_spell_seal")

#pragma comment(linker, "/export:ww_spell_shield=metamod_org.ww_spell_shield")

#pragma comment(linker, "/export:ww_spell_skull=metamod_org.ww_spell_skull")

#pragma comment(linker, "/export:ww_spell_spotbolt=metamod_org.ww_spell_spotbolt")

#pragma comment(linker, "/export:ww_spell_stone=metamod_org.ww_spell_stone")

#pragma comment(linker, "/export:ww_spell_thornblast=metamod_org.ww_spell_thornblast")

#pragma comment(linker, "/export:ww_spell_updraft=metamod_org.ww_spell_updraft")

#pragma comment(linker, "/export:ww_spell_whiteray=metamod_org.ww_spell_whiteray")

#pragma comment(linker, "/export:ww_spell_wyvern=metamod_org.ww_spell_wyvern")

#pragma comment(linker, "/export:ww_staff=metamod_org.ww_staff")

#pragma comment(linker, "/export:wyvern=metamod_org.wyvern")

#pragma comment(linker, "/export:xbow_teather=metamod_org.xbow_teather")

#pragma comment(linker, "/export:xbowbolt=metamod_org.xbowbolt")

#pragma comment(linker, "/export:xen_hair=metamod_org.xen_hair")

#pragma comment(linker, "/export:xen_hull=metamod_org.xen_hull")

#pragma comment(linker, "/export:xen_plantlight=metamod_org.xen_plantlight")

#pragma comment(linker, "/export:xen_spore_large=metamod_org.xen_spore_large")

#pragma comment(linker, "/export:xen_spore_medium=metamod_org.xen_spore_medium")

#pragma comment(linker, "/export:xen_spore_small=metamod_org.xen_spore_small")

#pragma comment(linker, "/export:xen_tree=metamod_org.xen_tree")

#pragma comment(linker, "/export:xen_ttrigger=metamod_org.xen_ttrigger")

#pragma comment(linker, "/export:zatarc_proj=metamod_org.zatarc_proj")

#pragma comment(linker, "/export:zone=metamod_org.zone")

#pragma comment(linker, "/export:zone_bomb_target=metamod_org.zone_bomb_target")

#pragma comment(linker, "/export:zone_capture=metamod_org.zone_capture")

#pragma comment(linker, "/export:zone_gatetravel=metamod_org.zone_gatetravel")

#pragma comment(linker, "/export:zone_nodamage=metamod_org.zone_nodamage")

#pragma comment(linker, "/export:zone_shelter=metamod_org.zone_shelter")

#pragma comment(linker, "/export:GetEntityAPI=metamod_org.GetEntityAPI")

#pragma comment(linker, "/export:GetEntityAPI2=metamod_org.GetEntityAPI2")

#pragma comment(linker, "/export:GetNewDLLFunctions=metamod_org.GetNewDLLFunctions")

#pragma comment(linker, "/export:GiveFnptrsToDll=metamod_org.GiveFnptrsToDll")

#pragma comment(linker, "/export:GiveFnptrsToDll=metamod_org.GiveFnptrsToDll")

#pragma comment(linker, "/export:Server_GetBlendingInterface=metamod_org.Server_GetBlendingInterface")

#pragma comment(linker, "/export:adminmod_timer=metamod_org.adminmod_timer")

#pragma endregion
