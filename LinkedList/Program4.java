import java.util.*;
class node
{
    int data;
    node next;

}
class List
{

    public node insert(node head,int data[])
    {
        node t=null;
        for(int i=0;i<data.length;i++) {
            node temp = new node();
            temp.data=data[i];
            if (head == null) {
                head = temp;
                t = temp;
            } else {
                t.next = temp;
                t=temp;
            }
        }
        return head;
    }
    public void show(node head)
    {
        if(head==null)
            return ;
        System.out.print(head.data+" ");
        show(head.next);
    }

}
public class Program4 {
    public static void main(String []args) {
    node head=null;
        int arr[]={1,4,2,6,3,8};
        List l=new List();
        head=l.insert(head,arr);
        l.show(head);
    }
}
