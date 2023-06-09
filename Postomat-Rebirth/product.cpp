#include "product.h"

QString operator>>(QString in, Product& p)
{
    int from = 0;
    int start = in.indexOf("<", from);
    int end = in.indexOf(">", start);

    while (start != -1 && end != -1)
    {
        QString tag = in.mid(start + 1, end - start - 1).toLower();
        start = end + 1;
        end = in.indexOf("</" + tag + ">", start, Qt::CaseSensitivity::CaseInsensitive);
        QString ins = in.mid(start, end - start);

        if (tag == "name")
        {
            p.name = ins;
        }
        else if (tag == "description")
        {
            p.description = ins;
        }
        else if (tag == "price")
        {
            p.price = ins;
        }
        else if (tag == "link")
        {
            p.link = ins;
        }

        from = end + tag.length() + 3;

        start = in.indexOf("<", from);
        end = in.indexOf(">", start);
    }

    return in;
}

QTextStream& operator<<(QTextStream& out, Product& p)
{
    out << "<name>" << p.name << "</name>\n";
    out << "<price>" << p.price << "</price>\n";
    out << "<description>" << p.description << "</description>\n";
    out << "<link>" << p.link << "</link>";
    return out;
}
