using UnityEngine;
using UnityEngine.UI;

public class ScorePlayer : MonoBehaviour
{
    public Text textBar;
    public CharacterController2D player;

    private void Awake()
    {
        player = GetComponent<CharacterController2D>();
    }

    private void FixedUpdate()
    {
        textBar.text = player.score.ToString();     
    }
}
