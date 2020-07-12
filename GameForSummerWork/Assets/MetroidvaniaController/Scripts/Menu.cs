using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI; //Работа с интерфейсами
using UnityEngine.SceneManagement; //Работа со сценами
using UnityEngine.Audio; //Работа с аудио

public class Menu : MonoBehaviour
{
    public void PlayGame()
    {
        SceneManager.LoadScene("Game");
    }

    public void QuitGame()
    {
        Application.Quit();
    }

    public AudioMixer am; //Регулятор громкости
    public float volume = 0; //Громкость
    public void ChangeVolume(float val) //Изменение звука
    {
        volume = val;
    }

    public int quality = 0; //Качество
    public void ChangeQuality(int index) //Изменение качества
    {
        quality = index;
    }

    public bool isFullscreen = false; //Полноэкранный режим
    public void ChangeFullscreenMode(bool val) //Включение или отключение полноэкранного режима
    {
        isFullscreen = val;
    }


    public Dropdown resolutionDropdown; //Список с разрешениями для игры
    private Resolution[] resolutions; //Список доступных разрешений
    private int currResolutionIndex = 0; //Текущее разрешение
    public void ChangeResolution(int index) //Изменение разрешения
    {
        currResolutionIndex = index;
    }
    public void SaveSettings()
    {
        am.SetFloat("masterVolume", volume); //Изменение уровня громкости
        QualitySettings.SetQualityLevel(quality); //Изменение качества
        Screen.fullScreen = isFullscreen; //Включение или отключение полноэкранного режима
        Screen.SetResolution(Screen.resolutions[currResolutionIndex].width, Screen.resolutions[currResolutionIndex].height, isFullscreen); //Изменения разрешения
    }
}
