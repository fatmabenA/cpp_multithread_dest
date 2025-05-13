

```cpp
#ifndef MERLIN_H
#define MERLIN_H

#include <boost/asio.hpp>
#include <QObject>

class Merlin : public QObject {
    Q_OBJECT

public:
    explicit Merlin(QObject *parent = nullptr);
    void run();

private:
    boost::asio::io_service io_service_;
    boost::asio::io_service::work work_;
};

#endif // MERLIN_H
```

```cpp
#include "Merlin.h"

Merlin::Merlin(QObject *parent) : QObject(parent), work_(io_service_) {}

void Merlin::run() {
    io_service_.run();
}
```