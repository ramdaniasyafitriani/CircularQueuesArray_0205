/**
 * @mainpage documentation circular Queues
 * @section introduction
 * project ini merupakan project struktur data
 * this project use strucur data queues, implements circular arrays..
 * 
 * @section operations
 * - en queue for insert elements into queues
 * - de queue for delete elements from queues 
 * - show data / display data
 * 
 * @section How to use
 * 1. insert
 * 2. delete
 * 3. display
 * 4. exit
 * 
 * @author yProfil
 * - Name : Ramdania Syafitriani
 * - Nim : 20240140205
 * - Class : E
 * 
 * @brief 
 * @version 0.1
 * @date 2025-06-23
 * 
 * @copyright Gibran@umy.ac.id (c) 2025
 * 
 */


#include <iostream>
using namespace std;

/**
 * @class Queues
 * @brief this class is for operation queues
 * 
 */

class Queues
{
private :
    /// private variable front for indicate first element
    int FRONT; 
    /// private variable rear for indicate last element
    int REAR; 
    /// private variable max for maximum capasity of element
    int max = 5;
    /// private variable queue_array to store elements
    int queue_array[5]; /// private variable queue_array to store elements

public :
    /**
     * @brief constructor a new queues object
     * set default queues null
     * with front = -1 and rear = -1
     * 
     */
    Queues()
    {
        FRONT = -1;
        REAR = -1;
    }
    /**
     * @brief method for entering data into a queue
     * - menambahkan element baru ke dalam struktur circular queues
     * - mengecek apakah antrian penuh atau tidak
     * - mengecek apakah antrian kosong
     * - apabila tidak penuh, tambahkan data ke posisi belakang (REAR) queue secara sirkular.
     * - mengatur posisi FRONT dan REAR sesuai kondisi queue.
     */
    void insert()
    {

        int num; /// public variable num for indicate number in elements
        cout << "Enter a number : "; 
        cin >> num; 
        cout << endl; 

        //mengecek apakah antrian penuh 
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) /// apabila 
        {
            cout << "\nQueue overflow\n";
            return;
        }

        // cek apakah antrian kosong 
        if (FRONT == -1)
        {
            FRONT = 0;
            REAR = 0;
        }
        else 
        {
            // jika REAR berada di posisi terakhir array, kembali ke awal array
            if (REAR == max - 1)
                REAR = 0;
            else 
                REAR = REAR + 1;
        }
        queue_array [REAR] = num;
    }

    /**
     * @brief method for deleted data into a queues 
     * 
     */
    void remove()

    {
        // cek apakah antrian kosong 
        if (FRONT == - 1)
        {
            cout << " Queue underflow\n";
            return;
        }
        cout << "\nThe Element deleted from the queue is : " << queue_array[FRONT] << "\n";

        // cek jika antrian hanya memiliki satu elemen 
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else 
        {
            // jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
            if (FRONT == max - 1)
                FRONT = 0;
            else 
                FRONT = FRONT + 1;
        }
    }

    /**
     * @brief method for display data into a queues 
     * menambahkan data kedalam posisi queues
     * 
     */
    void display()
    {
        int FRONT_position = FRONT; /// menyimpan posisi depan di dalam variabel FRONT
        int REAR_position = REAR; /// menyimpan posisi belakang di dalam variabel REAR

        // cek apakah antrian kosong 
        if (FRONT == - 1)
        {
            cout << " Queue is empty\n";
            return;
        }
        cout << "\nElements in the queue are...\n";

        // jika FRONT_position <= REAR_position, iterasi dari FRONT hingga REAR
        if (FRONT_position <= REAR_position)
        {
            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;
        }
        else 
        {
            // jika FRONT_position > REAR_position, iterasi dari FRONT hingga akhir array
            while (FRONT_position <= max - 1)
            {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            FRONT_position = 0;

            // iterasi dari awal array hingga REAR
            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;
        }
    }
};

/**
 * @brief menjalankan data agar dapat dieksekusi
 * 
 */
int main()
{
    Queues q; /// objek untuk menggunakan queues 
    char ch; /// objek untuk menyimpan pilihan yang akan dipilih

    while (true)
    {
        try 
        {
            cout << "Menu " << endl;
            cout << "1. Implement insert operation " << endl;
            cout << "2. Implement deleted operation " << endl;
            cout << "3. Display values " << endl;
            cout << "4. Exit " << endl;
            cout << " Enter your choice (1-4) : ";
            cin >> ch;
            cout << endl;

            switch (ch)
            {
            case '1':
            {
                q.insert();
                break;
            }
            case '2':
            {
                q.remove();
                break;   
            }
               case '3':
            {
                q.display();
                break;
            }
            case '4':
            {
                return 0;
            }
            default:
            {
                cout << " Invalid option!!" << endl;
                break;
            }
            }
        }
        catch (exception &e)
        {
            cout << " Check for the values entered. " << endl;
        }
    }
}