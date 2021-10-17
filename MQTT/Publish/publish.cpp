#include <mosquittopp.h>
#include <mosquitto.h>
#include <iostream>
#include <unistd.h>
#include <cstring>
using namespace std;

class myMosq : public mosqpp::mosquittopp
{
private:
    const char *host;
    const char *id;
    const char *topic;
    int port;
    int keepalive;

    void on_connect(int rc);
    void on_disconnect(int rc);
    void on_subscribe(int mid, int qos_count, const int *granted_qos);

public:
    myMosq(const char *id, const char *_topic, const char *host, int port);
    ~myMosq();
    bool send_message(const char *_message);
    bool receive_message(const char *_message);
    void on_message(const struct mosquitto_message *message);
};

myMosq::myMosq(const char *_id, const char *_topic, const char *_host, int _port) : mosquittopp(_id)
{
    mosqpp::lib_init();   // Mandatory initialization for mosquitto library
    this->keepalive = 60; // Basic configuration setup for myMosq class
    this->id = _id;
    this->port = _port;
    this->host = _host;
    this->topic = _topic;
    //connect_async(host, // non blocking connection to broker request
    //   port,
    //   keepalive);
    connect(host, // non blocking connection to broker request
            port,
            keepalive);
    //loop_start(); // Start thread managing connection / publish / subscribe
};

myMosq::~myMosq()
{
    //loop_stop();           // Kill the thread
    mosqpp::lib_cleanup(); // Mosquitto library cleanup
}

bool myMosq::send_message(const char *_message)
{
    int ret = publish(NULL, this->topic, strlen(_message), _message, 1, false);
    cout << ret;
    return (ret == MOSQ_ERR_SUCCESS);
}

bool myMosq::receive_message(const char *message)
{
    int set = subscribe(NULL, this->topic, 2);
    return set;
}
void myMosq::on_message(const struct mosquitto_message *message)
{
    cout << "Hey received message\n";
}
void myMosq::on_disconnect(int rc)
{
    std::cout << ">> myMosq - disconnection(" << rc << ")" << std::endl;
}

void myMosq::on_connect(int rc)
{
    if (rc == 0)
    {
        std::cout << ">> myMosq - connected with server" << std::endl;
    }
    else
    {
        std::cout << ">> myMosq - Impossible to connect with server(" << rc << ")" << std::endl;
    }
}

void myMosq::on_subscribe(int mid, int qos_count, const int *granted_qos)
{
    std::cout << ">> subscription succeeded (" << mid << ") " << std::endl;
    printf("Subscription succeeded.\n");
}

int main()
{

    myMosq *mosq;
    mosq = new myMosq("none", "test/tl", "localhost", 1883);
    int res;

    // res = mosq->loop(); // Keep MQTT connection
    // if (res)
    //     mosq->reconnect();
    while (1)
    {
        char tstr[500];
        cin.getline(tstr, sizeof(tstr));
        sleep(2);
        mosq->send_message(tstr);
        // mosq->receive_message(tstr);
    }
}