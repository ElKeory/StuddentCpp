using UnityEngine;

public class BonusRoom1 : MonoBehaviour
{
    public GameObject spawnEnemy;
    void OnTriggerEnter2D(Collider2D col)
    {
        if (col.gameObject.tag == "Player" && col.gameObject.GetComponent<CharacterController2D>().FirstEnter())
        {
            Instantiate(spawnEnemy, spawnEnemy.transform.position, Quaternion.identity);
        }
    }
}
