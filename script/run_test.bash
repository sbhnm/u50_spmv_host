
cd ../bin/
rm ../tmp/*

MATPATH=/home/zhouzhi/Document/Vitis_Accel_Examples/mix_precision/paper_matrix



mtx_list=($(ls  $MATPATH | grep TSOPF_RS_b300_c2.mtx))

for file in ${mtx_list[@]}
do
    rm ../tmp/*
    echo $file
    MATNAME=$file

    TMPFILEPATH=/home/zhouzhi/Document/u50_spmv_host/tmp/
    ./U50_SPMV_HOST ${MATPATH}/${MATNAME}  ${TMPFILEPATH} ${MATNAME}


    soBNNZ=$(cat ../tmp/${MATNAME}.cfg | grep soBNNZ | sed s/[^0-9]*//g)
    soBColIndex=$(cat ../tmp/${MATNAME}.cfg | grep soBColIndex | sed s/[^0-9]*//g)
    soBVal=$(cat ../tmp/${MATNAME}.cfg | grep soBVal | sed s/[^0-9]*//g)

    echo $soBNNZ
    echo $soBColIndex
    echo $soBVal

    echo 'calc end'
    
    read -n 1
done



