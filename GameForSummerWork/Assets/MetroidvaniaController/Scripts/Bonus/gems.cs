using UnityEngine;

public class gems : MonoBehaviour
{
    public GameObject bonus;
    void OnTriggerEnter2D(Collider2D col)
    {
        
        if (col.gameObject.tag == "Player")
        {
            GetComponentInParent <AudioSource>().Play();
            switch (bonus.tag)
            {
                case "gem1":
                    col.gameObject.GetComponent<CharacterController2D>().GetBonus(1f);
                    break;
                case "gem2":
                    col.gameObject.GetComponent<CharacterController2D>().GetBonus(2f);
                    break;
                case "gem3":
                    col.gameObject.GetComponent<CharacterController2D>().GetBonus(5f);
                    break;
                case "gem4":
                    col.gameObject.GetComponent<CharacterController2D>().GetBonus(10f);
                    break;
                case "Projectile":
                    col.gameObject.GetComponent<CharacterController2D>().GetShuriken(4);
                    break;
            }
            Destroy(bonus);
        }
    }

}
