#include "pch.h"
#include "Music.hpp"

MUSIC::TrackGroups MUSIC::MusicData::currentTrackGroup;
bool MUSIC::MusicData::finalWaveHI;
int last;

void MUSIC::PrepareTracks()
{
    int value = CALC::RanInt(6, 0);
    MusicData::currentTrackGroup = static_cast<TrackGroups>(value);
}

void MUSIC::StopTrack()
{
    AUDIO::TRIGGER_MUSIC_EVENT((char*)"MP_MC_STOP");
}

void MUSIC::StartTrack()
{
    switch (MusicData::currentTrackGroup)
    {
    case TrackGroups::SurvivalPrimary:
    {
        AUDIO::TRIGGER_MUSIC_EVENT((char*)"SM_W1_START_ALL");
        break;
    }
    case TrackGroups::BusinessBattle:
    {
        AUDIO::TRIGGER_MUSIC_EVENT((char*)"BTL_IDLE_START");
        break;
    }
    case TrackGroups::BikerContracts:
    {
        AUDIO::TRIGGER_MUSIC_EVENT((char*)"BIKER_SYG_START");
        break;
    }
    case TrackGroups::Casino:
    {
        AUDIO::TRIGGER_MUSIC_EVENT((char*)"CH_IDLE_START");
        break;
    }
    case TrackGroups::Casino2:
    {
        AUDIO::TRIGGER_MUSIC_EVENT((char*)"VWC_IDLE_START");
        break;
    }
    case TrackGroups::Tuner:
    {
        AUDIO::TRIGGER_MUSIC_EVENT((char*)"TUNER_IDLE_START");
        break;
    }
    case TrackGroups::Contract:
    {
        AUDIO::TRIGGER_MUSIC_EVENT((char*)"FIXER_IDLE_START");
        break;
    }
    default:
        break;
    }
}

void MUSIC::LowIntensityTrack()
{
    switch (MusicData::currentTrackGroup)
    {
    case TrackGroups::SurvivalPrimary:
    {
        AUDIO::TRIGGER_MUSIC_EVENT((char*)"SM_W1_END");
        break;
    }
    case TrackGroups::BusinessBattle:
    {
        AUDIO::TRIGGER_MUSIC_EVENT((char*)"BTL_IDLE");
        break;
    }
    case TrackGroups::BikerContracts:
    {
        AUDIO::TRIGGER_MUSIC_EVENT((char*)"BIKER_SYG_CALM");
        break;
    }
    case TrackGroups::Casino:
    {
        AUDIO::TRIGGER_MUSIC_EVENT((char*)"CH_SUSPENSE");
        break;
    }
    case TrackGroups::Casino2:
    {
        AUDIO::TRIGGER_MUSIC_EVENT((char*)"VWC_SUSPENSE");
        break;
    }
    case TrackGroups::Tuner:
    {
        AUDIO::TRIGGER_MUSIC_EVENT((char*)"TUNER_SUSPENSE");
        break;
    }
    case TrackGroups::Contract:
    {
        AUDIO::TRIGGER_MUSIC_EVENT((char*)"FIXER_SUSPENSE");
        break;
    }
    default:
        break;
    }
}

void MidIntensityTrack(int wave)
{
    switch (MUSIC::MusicData::currentTrackGroup)
    {
    case MUSIC::TrackGroups::SurvivalPrimary:
    {
        char evName[100];
        strcpy_s(evName, "SM_W");
        strcat_s(evName, std::to_string(wave > 10 ? 10 : wave).c_str());
        strcat_s(evName, "_MED");
        AUDIO::TRIGGER_MUSIC_EVENT(evName);
        break;
    }
    case MUSIC::TrackGroups::BusinessBattle:
    {
        if (wave <= 3)
        {
            AUDIO::TRIGGER_MUSIC_EVENT((char*)"BTL_MED_INTENSITY");
        }
        else
        {
            AUDIO::TRIGGER_MUSIC_EVENT((char*)"BTL_GUNFIGHT");
        }
        break;
    }
    case MUSIC::TrackGroups::BikerContracts:
    {
        if (wave <= 3)
        {
            AUDIO::TRIGGER_MUSIC_EVENT((char*)"BIKER_DEFEND_POLICE_RAID_FIGHT");
        }
        else
        {
            AUDIO::TRIGGER_MUSIC_EVENT((char*)"BIKER_SYG_ATTACKED");
        }
        break;
    }
    case MUSIC::TrackGroups::Casino:
    {
        if (wave <= 3)
        {
            AUDIO::TRIGGER_MUSIC_EVENT((char*)"CH_MED_INTENSITY");
        }
        else
        {
            AUDIO::TRIGGER_MUSIC_EVENT((char*)"CH_GUNFIGHT");
        }
        break;
    }
    case MUSIC::TrackGroups::Casino2:
    {
        if (wave <= 3)
        {
            AUDIO::TRIGGER_MUSIC_EVENT((char*)"VWC_MED_INTENSITY");
        }
        else
        {
           AUDIO::TRIGGER_MUSIC_EVENT((char*)"VWC_GUNFIGHT"); 
        }
        break;
    }
    case MUSIC::TrackGroups::Tuner:
    {
        if (wave <= 3)
        {
           AUDIO::TRIGGER_MUSIC_EVENT((char*)"TUNER_MED_INTENSITY"); 
        }
        else
        {
            AUDIO::TRIGGER_MUSIC_EVENT((char*)"TUNER_GUNFIGHT");
        }
        break;
    }
    case MUSIC::TrackGroups::Contract:
    {
        if (wave <= 3)
        {
            AUDIO::TRIGGER_MUSIC_EVENT((char*)"FIXER_MED_INTENSITY");
        }
        else
        {
            AUDIO::TRIGGER_MUSIC_EVENT((char*)"FIXER_GUNFIGHT");
        }
        break;
    }
    default:
        break;
    }
}

void HighIntensityTrack(int wave)
{
    switch (MUSIC::MusicData::currentTrackGroup)
    {
    case MUSIC::TrackGroups::SurvivalPrimary:
    {
        char evName[100];
        strcpy_s(evName, "SM_W");
        strcat_s(evName, std::to_string(wave > 10 ? 10 : wave).c_str());
        strcat_s(evName, "_HIGH");
        AUDIO::TRIGGER_MUSIC_EVENT(evName);
        break;
    }
    case MUSIC::TrackGroups::BusinessBattle:
    {
        AUDIO::TRIGGER_MUSIC_EVENT((char*)"BTL_VEHICLE_ACTION");
        break;
    }
    case MUSIC::TrackGroups::BikerContracts:
    {
        AUDIO::TRIGGER_MUSIC_EVENT((char*)"BIKER_DEFEND_CRASH_DEAL_DELIVERING");
        break;
    }
    case MUSIC::TrackGroups::Casino:
    {
        AUDIO::TRIGGER_MUSIC_EVENT((char*)"CH_VEHICLE_ACTION");
        break;
    }
    case MUSIC::TrackGroups::Casino2:
    {
        AUDIO::TRIGGER_MUSIC_EVENT((char*)"VWC_VEHICLE_ACTION");
        break;
    }
    case MUSIC::TrackGroups::Tuner:
    {
        AUDIO::TRIGGER_MUSIC_EVENT((char*)"TUNER_VEHICLE_ACTION");
        break;
    }
    case MUSIC::TrackGroups::Contract:
    {
        AUDIO::TRIGGER_MUSIC_EVENT((char*)"FIXER_VEHICLE_ACTION");
        break;
    }
    default:
        break;
    }
}

void MUSIC::Process(int enemyCount, int maxCount, int wave)
{
    int intensity = ceil((static_cast<float>(enemyCount) / static_cast<float>(maxCount)) * 10.0f);
    int max;

    if (intensity <= 0)
        intensity = 2;

    /*if (wave <= 3)
        max = 3;*/
    if (wave <= 6)
        max = 6;
    else
        max = 10;

    if (intensity > max)
        intensity = max;

    if (intensity != last)
        last = intensity;
    else
        return;

    if (last >= 7)
        HighIntensityTrack(last);
    else
        MidIntensityTrack(last);
}

void MUSIC::MissionCompletedSound()
{
    AUDIO::TRIGGER_MUSIC_EVENT((char*)"MP_DM_COUNTDOWN_KILL");
}

void MUSIC::FinalWaveMusic()
{
    AUDIO::TRIGGER_MUSIC_EVENT((char*)"BST_START");
}

void MUSIC::FinalWaveMusicHighIntensity()
{
    AUDIO::TRIGGER_MUSIC_EVENT((char*)"FIN1_SHOOTOUT_4");
}
