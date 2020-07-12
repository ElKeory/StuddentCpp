using UnityEngine;
using UnityEngine.UI;
public class HPplayer : MonoBehaviour
{
    public CharacterController2D m_CharacterController2D;
    public Image bar = null;
    public float fill;

    private void Awake()
    {
        m_CharacterController2D = GetComponent<CharacterController2D>();

    }
    public void Start()
    {
        fill = 1f;
    }

    public void FixedUpdate()
    {
        fill = m_CharacterController2D.life / 10f;
        bar.fillAmount = fill;
    }
}
