%%
%Author:honghuichao
%%
addpath('D:/caffe') %����+caffe·��  
caffe.set_mode_gpu();%����CPUģʽ  
model = 'D:/caffe/models/bvlc_reference_caffenet/deploy_copy.prototxt';%ģ��  
net=caffe.Net(model,'test');%����  
%net.copy_from(weights);
%[blob_w,blob_b]=AutoEncoder('C:\\Users\\Administrator\\Desktop\\pic2\\1\\',8,48);
net.params('conv1', 1).set_data(blob_w);
net.params('conv1', 2).set_data(blob_b); 

