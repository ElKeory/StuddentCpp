using UnityEngine;

public class DamageFromObjects : MonoBehaviour
{
    public float damage = 3f;
    void OnTriggerEnter2D(Collider2D col)
    {
        if (col.gameObject.tag == "Player")
        {
            col.gameObject.GetComponent<CharacterController2D>().GetDamageFromObject();
            col.gameObject.GetComponent<CharacterController2D>().ApplyDamage(damage, transform.position);
        }
    }
}
