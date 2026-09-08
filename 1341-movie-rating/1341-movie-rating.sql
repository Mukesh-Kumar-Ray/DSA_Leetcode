# Write your MySQL query statement below

(    SELECT 
        us.name AS results
    FROM MovieRating mv
    LEFT JOIN Users us
        ON mv.user_id = us.user_id
    GROUP BY us.user_id, us.name
    order by COUNT(*) desc ,us.name asc 
    limit 1)
    
    union all

    ( SELECT
        m.title AS results
    FROM Movies m
    JOIN MovieRating mr
        ON m.movie_id = mr.movie_id
    WHERE mr.created_at >= '2020-02-01'
      AND mr.created_at < '2020-03-01'
    GROUP BY m.movie_id, m.title
    ORDER BY AVG(mr.rating) DESC, m.title ASC
    LIMIT 1)
