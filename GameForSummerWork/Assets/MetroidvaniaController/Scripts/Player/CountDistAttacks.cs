using UnityEngine;
using UnityEngine.UI;

public class CountDistAttacks : MonoBehaviour
{
    private CharacterController2D player;
    public Text textBar;
    public void Awake()
    {
        player = GetComponent<CharacterController2D>();
    }
    
    public void FixedUpdate()
    {
        textBar.text = player.countShuriken.ToString();
    }
}
