-- NOTE: the string arguments are Russian data values stored in the original database:
--   'Склад 2' = 'Warehouse 2', 'Маркеры(10 шт)' = 'Markers (10 pcs)', 'Тетрадь 12л.' = 'Notebook 12 sheets'

-- tsk 4
select *
from proc_lab_8_task_4('25.02.2006', '18.09.2006');

--tsk 5
select *
from proc_lab_8_task_5('Склад 2', '25.02.2006', '18.05.2008');

--tsk 6
select *
from proc_lab_8_task_6('Маркеры(10 шт)', 500);

--tsk 7
select *
from proc_lab_8_task_7('Тетрадь 12л.', 2);

--tsk 8
select *
from proc_lab_8_task_8('25.02.2006', '18.09.2006');