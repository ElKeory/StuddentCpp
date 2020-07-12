using UnityEngine;

public class FirstAidKits : MonoBehaviour
{
    public GameObject firstaidkit;
    void OnTriggerEnter2D(Collider2D col)
    {
        if (col.gameObject.tag == "Player")
        {
            GetComponentInParent<AudioSource>().Play();
            switch (firstaidkit.name)
            {
                case "FirstAid1":
                    col.gameObject.GetComponent<CharacterController2D>().GetFirstAidKits(3f);
                    break;
                case "FirstAid2":
                    col.gameObject.GetComponent<CharacterController2D>().GetFirstAidKits(6f);
                    break;                
            }
            Destroy(firstaidkit);
        }
    }
}
