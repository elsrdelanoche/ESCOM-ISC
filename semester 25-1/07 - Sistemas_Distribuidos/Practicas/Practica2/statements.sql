-- Poblar tablas de dimensiones

INSERT INTO region (region)
SELECT DISTINCT region
FROM sales_data;

INSERT INTO country (country, id_region)
SELECT DISTINCT sd.country, r.id_region
FROM sales_data sd
JOIN region r ON sd.region = r.region;

INSERT INTO customer (customer)
SELECT DISTINCT customer
FROM sales_data;

INSERT INTO employee (employee)
SELECT DISTINCT employee
FROM sales_data;

INSERT INTO semester (semester)
SELECT DISTINCT semester
FROM sales_data;

INSERT INTO quarter (quarter, id_semester)
SELECT DISTINCT sd.quarter, s.id_semester
FROM sales_data sd
JOIN semester s ON sd.semester = s.semester;

INSERT INTO month (month, id_quarter)
SELECT DISTINCT sd.month, q.id_quarter
FROM sales_data sd
JOIN quarter q ON sd.quarter = q.quarter;

INSERT INTO weekday (weekday)
SELECT DISTINCT weekday
FROM sales_data;

INSERT INTO order_date (order_date, id_weekday, id_month)
SELECT DISTINCT sd.order_date, wd.id_weekday, m.id_month
FROM sales_data sd
JOIN weekday wd ON sd.weekday = wd.weekday
JOIN month m ON sd.month = m.month;

INSERT INTO category (category)
SELECT DISTINCT category
FROM sales_data;

INSERT INTO product (product, id_category)
SELECT DISTINCT sd.product, c.id_category
FROM sales_data sd
JOIN category c ON sd.category = c.category;

-- Poblar la tabla de hechos

INSERT INTO fact_table (sales, id_order_date, id_product, id_customer, id_country, id_employee)
SELECT
    sd.sales,
    od.id_order_date,
    p.id_product,
    c.id_customer,
    cn.id_country,
    e.id_employee
FROM sales_data sd
JOIN order_date od ON sd.order_date = od.order_date
JOIN product p ON sd.product = p.product
JOIN customer c ON sd.customer = c.customer
JOIN country cn ON sd.country = cn.country
JOIN employee e ON sd.employee = e.employee;

-- Poblar tablas agregadas

INSERT INTO country_category_product (id_country, id_category, id_product, sales)
SELECT cn.id_country, c.id_category, p.id_product, SUM(sd.sales)
FROM sales_data sd
JOIN country cn ON sd.country = cn.country
JOIN category c ON sd.category = c.category
JOIN product p ON sd.product = p.product
GROUP BY cn.id_country, c.id_category, p.id_product;

INSERT INTO country_quarter_category (id_country, id_quarter, id_category, sales)
SELECT cn.id_country, q.id_quarter, c.id_category, SUM(sd.sales)
FROM sales_data sd
JOIN country cn ON sd.country = cn.country
JOIN quarter q ON sd.quarter = q.quarter
JOIN category c ON sd.category = c.category
GROUP BY cn.id_country, q.id_quarter, c.id_category;

INSERT INTO country_weekday_product (id_country, id_weekday, id_product, sales)
SELECT cn.id_country, wd.id_weekday, p.id_product, SUM(sd.sales)
FROM sales_data sd
JOIN country cn ON sd.country = cn.country
JOIN weekday wd ON sd.weekday = wd.weekday
JOIN product p ON sd.product = p.product
GROUP BY cn.id_country, wd.id_weekday, p.id_product;
