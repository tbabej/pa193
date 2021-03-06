#ifndef SHOPITEM_H
#define SHOPITEM_H

#include <iostream>
#include <stdexcept>
#include <list>

#include "urls.h"
#include "delivery.h"
#include "param.h"


class ShopItem {
    std::string* m_id; //musi byt unikatne, max 36 znakov [a-z][A-Z][0-9] - _
    std::string* m_prodName;//musi byt v product, max 255 znakov
    std::string* m_product; // max 255 znakov
    std::string* m_desc;

    Urls* m_urls; //(validacia nedokoncena)

    double m_price;//2 desatinne miesta
    std::string* m_itemType;
    std::string* m_manufact;//musi byt v product name
    std::string* m_catText;

    unsigned long long m_ean; //povinny pre kinhy
    unsigned long long m_isbn;//isbn10, isbn13
    double m_heuCpc; // max 100, 2 desatinne miesta

    std::string* m_delivery_date;
    std::list<Delivery*> m_delivery;
    std::list<Param*> m_param;

    std::string* m_groupId;//max 36 znakov [a-z][A-Z][0-9] - _
    std::list<std::string> m_accessory; //obsahuje id inych poloziek
    double m_dues;//ine poplatky

    void validateId(const std::string & str) const;
    void validateProduct(const std::string& str) const;
    unsigned int computeEanChecksum(const unsigned long long digits) const;
    unsigned int computeIsbn10Checksum(const unsigned long long digits) const;
public:

    ShopItem();

    ~ShopItem();

    void setId(const std::string & id);

    void setProdName(const std::string & name);

    void setProduct(const std::string & product);

    void setDesc(const std::string & desc);

    void setPrice(const double price);

    void setItemType(const std::string& type);

    void setManufacturer(const std::string& manuf);

    void setCatText(const std::string& category);

    void setEan(const unsigned long long ean);

    void setIsbn10(const unsigned long long isbn);

    void setHeuCpc(const double val);

    void setItemGroupId(const std::string & id);

    void addAccessory(const std::string& accessory);

    void setDues(const double due);

    void setDeliveryDate(const std::string& deliveryDate);

    void addDelivery(Delivery* delivery);

    void addParam(Param* param);

    void setUrl(const std::string& url);

    void setImgUrl(const std::string& url);

    void addAltUrl(const std::string& url);

    void setVidUrl(const std::string& url);

    std::string* getId() const;

    std::string* getProdName() const;

    std::string* getProduct() const;

    std::string* getDesc() const;

    Urls* getUrls() const;

    double getPrice() const;

    std::string* getItemType() const;

    std::string* getManufact() const;

    std::string* getCatText() const;

    unsigned long long getEAN() const;
};


#endif // SHOPITEM_H
