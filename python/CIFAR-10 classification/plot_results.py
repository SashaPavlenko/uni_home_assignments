import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

# Data for tasks 5.1, 5.2, 5.3
tasks_data = {
    "5.1": {
        "accuracy": [
            44.98, 41.59, 55.02, 58.44, 57.45, 60.91, 51.78, 60.75, 55.23, 63.15,
            64.75, 63.82, 64.16, 66.18, 62.72, 61.06, 54.73, 63.45, 68.82, 65.76,
            68.78, 68.21, 61.56, 58.73, 68.83, 64.04, 69.75, 64.6, 65.1, 69.78
        ],
        "time": 1140.59,
        "final_acc": 69.78,
        "label": "Task 5.1 (transformations only)"
    },
    "5.2": {
        "accuracy": [
            49.48, 58.02, 55.99, 58.16, 59.85, 60.75, 58.88, 64.07, 58.9, 65.12,
            64.47, 65.07, 60.82, 60.01, 66.93, 63.26, 66.84, 67.48, 69.29, 63.13,
            62.46, 67.2, 68.79, 68.59, 65.49, 66.17, 70.35, 68.9, 70.53, 68.78
        ],
        "time": 1145.60,
        "final_acc": 70.53,
        "label": "Task 5.2 (with skip connections)"
    },
    "5.3": {
        "accuracy": [
            41.64, 52.04, 53.11, 57.23, 59.54, 65.83, 65.28, 70.03, 67.34, 71.38,
            72.16, 72.35, 73.46, 74.54, 71.82, 75.01, 76.51, 77.19, 75.9, 74.21,
            76.92, 75.55, 78.61, 79.32, 77.7, 78.73, 80.02, 80.74, 79.26, 80.06
        ],
        "time": 1194.35,
        "final_acc": 80.06,
        "label": "Task 5.3 (added params, normalization in transforms)"
    }
}

# Plot training curves
plt.figure(figsize=(10, 6))
for key, task in tasks_data.items():
    plt.plot(task["accuracy"], label=task["label"])
plt.title("Test Accuracy over Epochs (Task 5 Variants)")
plt.xlabel("Epoch")
plt.ylabel("Test Accuracy (%)")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("acc_loss_task5.pdf")
plt.show()


import re
raw_text = """task 0
Train Epoch: 0, Loss: 2.3012
Test: Average loss: 2.2948, Accuracy: 1001/10000 (10.01%)
Train Epoch: 1, Loss: 2.2548
Test: Average loss: 2.1549, Accuracy: 2113/10000 (21.13%)
Train Epoch: 2, Loss: 2.0458
Test: Average loss: 1.9815, Accuracy: 2743/10000 (27.43%)
Train Epoch: 3, Loss: 1.9509
Test: Average loss: 1.8991, Accuracy: 2999/10000 (29.99%)
Train Epoch: 4, Loss: 1.8440
Test: Average loss: 1.7688, Accuracy: 3623/10000 (36.23%)
Train Epoch: 5, Loss: 1.7117
Test: Average loss: 1.6443, Accuracy: 4034/10000 (40.34%)
Train Epoch: 6, Loss: 1.6053
Test: Average loss: 1.6818, Accuracy: 3793/10000 (37.93%)
Train Epoch: 7, Loss: 1.5307
Test: Average loss: 1.6205, Accuracy: 4131/10000 (41.31%)
Train Epoch: 8, Loss: 1.4752
Test: Average loss: 1.6336, Accuracy: 4014/10000 (40.14%)
Train Epoch: 9, Loss: 1.4307
Test: Average loss: 1.4873, Accuracy: 4633/10000 (46.33%)
Train Epoch: 10, Loss: 1.3973
Test: Average loss: 1.4636, Accuracy: 4709/10000 (47.09%)
Train Epoch: 11, Loss: 1.3679
Test: Average loss: 1.4220, Accuracy: 4898/10000 (48.98%)
Train Epoch: 12, Loss: 1.3405
Test: Average loss: 1.3880, Accuracy: 5085/10000 (50.85%)
Train Epoch: 13, Loss: 1.3131
Test: Average loss: 1.3968, Accuracy: 5037/10000 (50.37%)
Train Epoch: 14, Loss: 1.2895
Test: Average loss: 1.3084, Accuracy: 5301/10000 (53.01%)
Train Epoch: 15, Loss: 1.2687
Test: Average loss: 1.3557, Accuracy: 5118/10000 (51.18%)
Train Epoch: 16, Loss: 1.2472
Test: Average loss: 1.3946, Accuracy: 5038/10000 (50.38%)
Train Epoch: 17, Loss: 1.2237
Test: Average loss: 1.2849, Accuracy: 5330/10000 (53.30%)
Train Epoch: 18, Loss: 1.2044
Test: Average loss: 1.5090, Accuracy: 4781/10000 (47.81%)
Train Epoch: 19, Loss: 1.1843
Test: Average loss: 1.4528, Accuracy: 4959/10000 (49.59%)
Train Epoch: 20, Loss: 1.1699
Test: Average loss: 1.2722, Accuracy: 5449/10000 (54.49%)
Train Epoch: 21, Loss: 1.1499
Test: Average loss: 1.2759, Accuracy: 5485/10000 (54.85%)
Train Epoch: 22, Loss: 1.1353
Test: Average loss: 1.4630, Accuracy: 5003/10000 (50.03%)
Train Epoch: 23, Loss: 1.1182
Test: Average loss: 1.4358, Accuracy: 4969/10000 (49.69%)
Train Epoch: 24, Loss: 1.1015
Test: Average loss: 1.3602, Accuracy: 5266/10000 (52.66%)
Train Epoch: 25, Loss: 1.0874
Test: Average loss: 1.2109, Accuracy: 5715/10000 (57.15%)
Train Epoch: 26, Loss: 1.0689
Test: Average loss: 1.2476, Accuracy: 5642/10000 (56.42%)
Train Epoch: 27, Loss: 1.0573
Test: Average loss: 1.2276, Accuracy: 5676/10000 (56.76%)
Train Epoch: 28, Loss: 1.0415
Test: Average loss: 1.2484, Accuracy: 5618/10000 (56.18%)
Train Epoch: 29, Loss: 1.0300
Test: Average loss: 1.2277, Accuracy: 5710/10000 (57.10%)
Total training and inference time is: 297.09780716896057
Test: Average loss: 1.2277, Accuracy: 5710/10000 (57.10%)
Total inference time is: 1.2820937633514404
Total Training time is: 258.63499426841736

task 1.1
Train Epoch: 0, Loss: 2.3015
Test: Average loss: 2.2958, Accuracy: 1024/10000 (10.24%)
Train Epoch: 1, Loss: 2.2547
Test: Average loss: 2.1638, Accuracy: 1817/10000 (18.17%)
Train Epoch: 2, Loss: 2.0509
Test: Average loss: 1.9761, Accuracy: 2845/10000 (28.45%)
Train Epoch: 3, Loss: 1.9484
Test: Average loss: 1.9326, Accuracy: 2971/10000 (29.71%)
Train Epoch: 4, Loss: 1.8727
Test: Average loss: 1.8155, Accuracy: 3486/10000 (34.86%)
Train Epoch: 5, Loss: 1.7930
Test: Average loss: 1.7571, Accuracy: 3692/10000 (36.92%)
Train Epoch: 6, Loss: 1.7215
Test: Average loss: 1.8176, Accuracy: 3342/10000 (33.42%)
Train Epoch: 7, Loss: 1.6619
Test: Average loss: 1.6352, Accuracy: 4137/10000 (41.37%)
Train Epoch: 8, Loss: 1.6062
Test: Average loss: 1.7453, Accuracy: 3705/10000 (37.05%)
Train Epoch: 9, Loss: 1.5538
Test: Average loss: 1.5447, Accuracy: 4394/10000 (43.94%)
Train Epoch: 10, Loss: 1.5101
Test: Average loss: 1.6715, Accuracy: 4047/10000 (40.47%)
Train Epoch: 11, Loss: 1.4720
Test: Average loss: 1.4978, Accuracy: 4588/10000 (45.88%)
Train Epoch: 12, Loss: 1.4426
Test: Average loss: 1.5155, Accuracy: 4667/10000 (46.67%)
Train Epoch: 13, Loss: 1.4106
Test: Average loss: 1.4228, Accuracy: 4861/10000 (48.61%)
Train Epoch: 14, Loss: 1.3877
Test: Average loss: 1.4023, Accuracy: 5030/10000 (50.30%)
Train Epoch: 15, Loss: 1.3628
Test: Average loss: 1.4018, Accuracy: 4953/10000 (49.53%)
Train Epoch: 16, Loss: 1.3419
Test: Average loss: 1.4056, Accuracy: 4984/10000 (49.84%)
Train Epoch: 17, Loss: 1.3202
Test: Average loss: 1.3775, Accuracy: 5035/10000 (50.35%)
Train Epoch: 18, Loss: 1.3004
Test: Average loss: 1.4591, Accuracy: 4804/10000 (48.04%)
Train Epoch: 19, Loss: 1.2841
Test: Average loss: 1.4719, Accuracy: 4832/10000 (48.32%)
Train Epoch: 20, Loss: 1.2677
Test: Average loss: 1.3671, Accuracy: 5114/10000 (51.14%)
Train Epoch: 21, Loss: 1.2510
Test: Average loss: 1.3549, Accuracy: 5209/10000 (52.09%)
Train Epoch: 22, Loss: 1.2351
Test: Average loss: 1.4657, Accuracy: 4892/10000 (48.92%)
Train Epoch: 23, Loss: 1.2192
Test: Average loss: 1.3870, Accuracy: 5066/10000 (50.66%)
Train Epoch: 24, Loss: 1.2041
Test: Average loss: 1.3570, Accuracy: 5197/10000 (51.97%)
Train Epoch: 25, Loss: 1.1894
Test: Average loss: 1.2992, Accuracy: 5419/10000 (54.19%)
Train Epoch: 26, Loss: 1.1748
Test: Average loss: 1.3011, Accuracy: 5414/10000 (54.14%)
Train Epoch: 27, Loss: 1.1622
Test: Average loss: 1.3523, Accuracy: 5259/10000 (52.59%)
Train Epoch: 28, Loss: 1.1498
Test: Average loss: 1.3142, Accuracy: 5367/10000 (53.67%)
Train Epoch: 29, Loss: 1.1368
Test: Average loss: 1.3369, Accuracy: 5332/10000 (53.32%)
Total training and inference time is: 297.1714222431183
Test: Average loss: 1.3369, Accuracy: 5332/10000 (53.32%)
Total inference time is: 1.2898650169372559
Total Training time is: 258.4754717350006


task 1.2
Train Epoch: 0, Loss: 2.3010
Test: Average loss: 2.2935, Accuracy: 1032/10000 (10.32%)
Train Epoch: 1, Loss: 2.2433
Test: Average loss: 2.1455, Accuracy: 1898/10000 (18.98%)
Train Epoch: 2, Loss: 2.0509
Test: Average loss: 1.9765, Accuracy: 2793/10000 (27.93%)
Train Epoch: 3, Loss: 1.9459
Test: Average loss: 1.9208, Accuracy: 2970/10000 (29.70%)
Train Epoch: 4, Loss: 1.8702
Test: Average loss: 1.8279, Accuracy: 3437/10000 (34.37%)
Train Epoch: 5, Loss: 1.7951
Test: Average loss: 1.7551, Accuracy: 3672/10000 (36.72%)
Train Epoch: 6, Loss: 1.7330
Test: Average loss: 1.8253, Accuracy: 3327/10000 (33.27%)
Train Epoch: 7, Loss: 1.6752
Test: Average loss: 1.6797, Accuracy: 3826/10000 (38.26%)
Train Epoch: 8, Loss: 1.6184
Test: Average loss: 1.7908, Accuracy: 3524/10000 (35.24%)
Train Epoch: 9, Loss: 1.5692
Test: Average loss: 1.5778, Accuracy: 4271/10000 (42.71%)
Train Epoch: 10, Loss: 1.5325
Test: Average loss: 1.8037, Accuracy: 3713/10000 (37.13%)
Train Epoch: 11, Loss: 1.5015
Test: Average loss: 1.6293, Accuracy: 4164/10000 (41.64%)
Train Epoch: 12, Loss: 1.4750
Test: Average loss: 1.5511, Accuracy: 4409/10000 (44.09%)
Train Epoch: 13, Loss: 1.4478
Test: Average loss: 1.4541, Accuracy: 4769/10000 (47.69%)
Train Epoch: 14, Loss: 1.4251
Test: Average loss: 1.4806, Accuracy: 4750/10000 (47.50%)
Train Epoch: 15, Loss: 1.4040
Test: Average loss: 1.4581, Accuracy: 4752/10000 (47.52%)
Train Epoch: 16, Loss: 1.3834
Test: Average loss: 1.5377, Accuracy: 4614/10000 (46.14%)
Train Epoch: 17, Loss: 1.3617
Test: Average loss: 1.4414, Accuracy: 4792/10000 (47.92%)
Train Epoch: 18, Loss: 1.3439
Test: Average loss: 1.4778, Accuracy: 4756/10000 (47.56%)
Train Epoch: 19, Loss: 1.3276
Test: Average loss: 1.7867, Accuracy: 4133/10000 (41.33%)
Train Epoch: 20, Loss: 1.3094
Test: Average loss: 1.4205, Accuracy: 4985/10000 (49.85%)
Train Epoch: 21, Loss: 1.2917
Test: Average loss: 1.4130, Accuracy: 4998/10000 (49.98%)
Train Epoch: 22, Loss: 1.2755
Test: Average loss: 1.4787, Accuracy: 4766/10000 (47.66%)
Train Epoch: 23, Loss: 1.2608
Test: Average loss: 1.3854, Accuracy: 5066/10000 (50.66%)
Train Epoch: 24, Loss: 1.2420
Test: Average loss: 1.4219, Accuracy: 5042/10000 (50.42%)
Train Epoch: 25, Loss: 1.2270
Test: Average loss: 1.3376, Accuracy: 5267/10000 (52.67%)
Train Epoch: 26, Loss: 1.2112
Test: Average loss: 1.3737, Accuracy: 5157/10000 (51.57%)
Train Epoch: 27, Loss: 1.1971
Test: Average loss: 1.3811, Accuracy: 5103/10000 (51.03%)
Train Epoch: 28, Loss: 1.1838
Test: Average loss: 1.3734, Accuracy: 5224/10000 (52.24%)
Train Epoch: 29, Loss: 1.1688
Test: Average loss: 1.3710, Accuracy: 5151/10000 (51.51%)
Total training and inference time is: 283.9678237438202
Test: Average loss: 1.3710, Accuracy: 5151/10000 (51.51%)
Total inference time is: 1.3405365943908691
Total Training time is: 243.75172591209412

task 2
Train Epoch: 0, Loss: 2.3022
Test: Average loss: 2.2977, Accuracy: 1009/10000 (10.09%)
Train Epoch: 1, Loss: 2.2853
Test: Average loss: 2.2393, Accuracy: 1821/10000 (18.21%)
Train Epoch: 2, Loss: 2.1826
Test: Average loss: 2.1049, Accuracy: 2201/10000 (22.01%)
Train Epoch: 3, Loss: 2.1005
Test: Average loss: 2.0445, Accuracy: 2389/10000 (23.89%)
Train Epoch: 4, Loss: 2.0516
Test: Average loss: 1.9733, Accuracy: 2557/10000 (25.57%)
Train Epoch: 5, Loss: 2.0019
Test: Average loss: 1.9094, Accuracy: 2936/10000 (29.36%)
Train Epoch: 6, Loss: 1.9294
Test: Average loss: 1.8783, Accuracy: 3132/10000 (31.32%)
Train Epoch: 7, Loss: 1.8642
Test: Average loss: 1.8309, Accuracy: 3487/10000 (34.87%)
Train Epoch: 8, Loss: 1.8152
Test: Average loss: 1.8198, Accuracy: 3431/10000 (34.31%)
Train Epoch: 9, Loss: 1.7677
Test: Average loss: 1.6391, Accuracy: 4021/10000 (40.21%)
Train Epoch: 10, Loss: 1.7179
Test: Average loss: 1.6881, Accuracy: 3962/10000 (39.62%)
Train Epoch: 11, Loss: 1.6802
Test: Average loss: 1.5911, Accuracy: 4247/10000 (42.47%)
Train Epoch: 12, Loss: 1.6429
Test: Average loss: 1.6039, Accuracy: 4267/10000 (42.67%)
Train Epoch: 13, Loss: 1.6152
Test: Average loss: 1.4888, Accuracy: 4599/10000 (45.99%)
Train Epoch: 14, Loss: 1.5934
Test: Average loss: 1.5818, Accuracy: 4326/10000 (43.26%)
Train Epoch: 15, Loss: 1.5696
Test: Average loss: 1.4601, Accuracy: 4701/10000 (47.01%)
Train Epoch: 16, Loss: 1.5527
Test: Average loss: 1.4697, Accuracy: 4645/10000 (46.45%)
Train Epoch: 17, Loss: 1.5347
Test: Average loss: 1.4349, Accuracy: 4843/10000 (48.43%)
Train Epoch: 18, Loss: 1.5179
Test: Average loss: 1.4737, Accuracy: 4652/10000 (46.52%)
Train Epoch: 19, Loss: 1.5026
Test: Average loss: 1.5221, Accuracy: 4555/10000 (45.55%)
Train Epoch: 20, Loss: 1.4883
Test: Average loss: 1.4009, Accuracy: 4883/10000 (48.83%)
Train Epoch: 21, Loss: 1.4762
Test: Average loss: 1.5167, Accuracy: 4701/10000 (47.01%)
Train Epoch: 22, Loss: 1.4612
Test: Average loss: 1.4076, Accuracy: 4878/10000 (48.78%)
Train Epoch: 23, Loss: 1.4526
Test: Average loss: 1.3852, Accuracy: 4994/10000 (49.94%)
Train Epoch: 24, Loss: 1.4368
Test: Average loss: 1.3561, Accuracy: 5156/10000 (51.56%)
Train Epoch: 25, Loss: 1.4190
Test: Average loss: 1.3229, Accuracy: 5279/10000 (52.79%)
Train Epoch: 26, Loss: 1.4120
Test: Average loss: 1.3224, Accuracy: 5239/10000 (52.39%)
Train Epoch: 27, Loss: 1.4008
Test: Average loss: 1.3264, Accuracy: 5242/10000 (52.42%)
Train Epoch: 28, Loss: 1.3871
Test: Average loss: 1.2985, Accuracy: 5364/10000 (53.64%)
Train Epoch: 29, Loss: 1.3757
Test: Average loss: 1.2874, Accuracy: 5400/10000 (54.00%)
Total training and inference time is: 296.92042350769043
Test: Average loss: 1.2874, Accuracy: 5400/10000 (54.00%)
Total inference time is: 1.6438517570495605
Total Training time is: 247.6048707962036

task 3
Train Epoch: 0, Loss: 1.7063
Test: Average loss: 1.5439, Accuracy: 4424/10000 (44.24%)
Train Epoch: 1, Loss: 1.4042
Test: Average loss: 1.6460, Accuracy: 4077/10000 (40.77%)
Train Epoch: 2, Loss: 1.2837
Test: Average loss: 1.6046, Accuracy: 4577/10000 (45.77%)
Train Epoch: 3, Loss: 1.2030
Test: Average loss: 1.5775, Accuracy: 4677/10000 (46.77%)
Train Epoch: 4, Loss: 1.1353
Test: Average loss: 1.3143, Accuracy: 5263/10000 (52.63%)
Train Epoch: 5, Loss: 1.0812
Test: Average loss: 1.8740, Accuracy: 4224/10000 (42.24%)
Train Epoch: 6, Loss: 1.0321
Test: Average loss: 2.0258, Accuracy: 4045/10000 (40.45%)
Train Epoch: 7, Loss: 0.9909
Test: Average loss: 1.3564, Accuracy: 5374/10000 (53.74%)
Train Epoch: 8, Loss: 0.9556
Test: Average loss: 1.3383, Accuracy: 5354/10000 (53.54%)
Train Epoch: 9, Loss: 0.9230
Test: Average loss: 1.1347, Accuracy: 6066/10000 (60.66%)
Train Epoch: 10, Loss: 0.8942
Test: Average loss: 1.6892, Accuracy: 4449/10000 (44.49%)
Train Epoch: 11, Loss: 0.8684
Test: Average loss: 1.4018, Accuracy: 5271/10000 (52.71%)
Train Epoch: 12, Loss: 0.8420
Test: Average loss: 1.5319, Accuracy: 5175/10000 (51.75%)
Train Epoch: 13, Loss: 0.8156
Test: Average loss: 1.0428, Accuracy: 6403/10000 (64.03%)
Train Epoch: 14, Loss: 0.7929
Test: Average loss: 1.9258, Accuracy: 4287/10000 (42.87%)
Train Epoch: 15, Loss: 0.7753
Test: Average loss: 1.7119, Accuracy: 4831/10000 (48.31%)
Train Epoch: 16, Loss: 0.7539
Test: Average loss: 1.3415, Accuracy: 5529/10000 (55.29%)
Train Epoch: 17, Loss: 0.7373
Test: Average loss: 1.5677, Accuracy: 5271/10000 (52.71%)
Train Epoch: 18, Loss: 0.7181
Test: Average loss: 1.0086, Accuracy: 6606/10000 (66.06%)
Train Epoch: 19, Loss: 0.7019
Test: Average loss: 1.1988, Accuracy: 6038/10000 (60.38%)
Train Epoch: 20, Loss: 0.6846
Test: Average loss: 1.1346, Accuracy: 6209/10000 (62.09%)
Train Epoch: 21, Loss: 0.6678
Test: Average loss: 2.1931, Accuracy: 4199/10000 (41.99%)
Train Epoch: 22, Loss: 0.6566
Test: Average loss: 1.3106, Accuracy: 6024/10000 (60.24%)
Train Epoch: 23, Loss: 0.6403
Test: Average loss: 1.4256, Accuracy: 5646/10000 (56.46%)
Train Epoch: 24, Loss: 0.6250
Test: Average loss: 1.1087, Accuracy: 6432/10000 (64.32%)
Train Epoch: 25, Loss: 0.6140
Test: Average loss: 1.0413, Accuracy: 6578/10000 (65.78%)
Train Epoch: 26, Loss: 0.5989
Test: Average loss: 1.0805, Accuracy: 6467/10000 (64.67%)
Train Epoch: 27, Loss: 0.5941
Test: Average loss: 1.1594, Accuracy: 6246/10000 (62.46%)
Train Epoch: 28, Loss: 0.5756
Test: Average loss: 1.3160, Accuracy: 5832/10000 (58.32%)
Train Epoch: 29, Loss: 0.5637
Test: Average loss: 1.5676, Accuracy: 5451/10000 (54.51%)
Total training and inference time is: 305.9295961856842
Test: Average loss: 1.5676, Accuracy: 5451/10000 (54.51%)
Total inference time is: 1.3014650344848633
Total Training time is: 266.8856451511383

task 4
Train Epoch: 0, Loss: 1.9588
Test: Average loss: 1.8283, Accuracy: 3364/10000 (33.64%)
Train Epoch: 1, Loss: 1.6914
Test: Average loss: 2.2537, Accuracy: 2409/10000 (24.09%)
Train Epoch: 2, Loss: 1.5965
Test: Average loss: 1.4929, Accuracy: 4678/10000 (46.78%)
Train Epoch: 3, Loss: 1.5347
Test: Average loss: 1.4041, Accuracy: 4929/10000 (49.29%)
Train Epoch: 4, Loss: 1.4911
Test: Average loss: 1.6910, Accuracy: 4050/10000 (40.50%)
Train Epoch: 5, Loss: 1.4486
Test: Average loss: 1.3621, Accuracy: 5154/10000 (51.54%)
Train Epoch: 6, Loss: 1.4090
Test: Average loss: 1.9799, Accuracy: 3699/10000 (36.99%)
Train Epoch: 7, Loss: 1.3817
Test: Average loss: 2.1589, Accuracy: 3462/10000 (34.62%)
Train Epoch: 8, Loss: 1.3547
Test: Average loss: 1.8200, Accuracy: 3920/10000 (39.20%)
Train Epoch: 9, Loss: 1.3341
Test: Average loss: 1.5772, Accuracy: 4319/10000 (43.19%)
Train Epoch: 10, Loss: 1.3111
Test: Average loss: 1.7866, Accuracy: 4039/10000 (40.39%)
Train Epoch: 11, Loss: 1.2940
Test: Average loss: 1.1899, Accuracy: 5801/10000 (58.01%)
Train Epoch: 12, Loss: 1.2753
Test: Average loss: 1.1985, Accuracy: 5774/10000 (57.74%)
Train Epoch: 13, Loss: 1.2622
Test: Average loss: 1.2687, Accuracy: 5482/10000 (54.82%)
Train Epoch: 14, Loss: 1.2429
Test: Average loss: 1.3487, Accuracy: 5184/10000 (51.84%)
Train Epoch: 15, Loss: 1.2262
Test: Average loss: 1.3460, Accuracy: 5157/10000 (51.57%)
Train Epoch: 16, Loss: 1.2202
Test: Average loss: 1.1731, Accuracy: 5757/10000 (57.57%)
Train Epoch: 17, Loss: 1.2038
Test: Average loss: 1.3760, Accuracy: 5112/10000 (51.12%)
Train Epoch: 18, Loss: 1.1926
Test: Average loss: 1.1885, Accuracy: 5819/10000 (58.19%)
Train Epoch: 19, Loss: 1.1773
Test: Average loss: 1.1888, Accuracy: 5864/10000 (58.64%)
Train Epoch: 20, Loss: 1.1745
Test: Average loss: 1.1471, Accuracy: 5988/10000 (59.88%)
Train Epoch: 21, Loss: 1.1646
Test: Average loss: 1.5751, Accuracy: 4576/10000 (45.76%)
Train Epoch: 22, Loss: 1.1518
Test: Average loss: 1.4514, Accuracy: 4859/10000 (48.59%)
Train Epoch: 23, Loss: 1.1502
Test: Average loss: 1.1191, Accuracy: 6106/10000 (61.06%)
Train Epoch: 24, Loss: 1.1418
Test: Average loss: 1.0794, Accuracy: 6192/10000 (61.92%)
Train Epoch: 25, Loss: 1.1315
Test: Average loss: 1.1851, Accuracy: 5892/10000 (58.92%)
Train Epoch: 26, Loss: 1.1242
Test: Average loss: 1.4523, Accuracy: 5076/10000 (50.76%)
Train Epoch: 27, Loss: 1.1204
Test: Average loss: 1.1580, Accuracy: 5920/10000 (59.20%)
Train Epoch: 28, Loss: 1.1102
Test: Average loss: 1.0893, Accuracy: 6178/10000 (61.78%)
Train Epoch: 29, Loss: 1.1082
Test: Average loss: 1.2983, Accuracy: 5481/10000 (54.81%)
Total training and inference time is: 310.2839369773865
Test: Average loss: 1.2983, Accuracy: 5481/10000 (54.81%)
Total inference time is: 1.3151631355285645
Total Training time is: 270.82904291152954"""

# Re-split without using capturing group to avoid introducing None values
task_blocks_clean = re.split(r'\ntask \d+(?:\.\d+)?\n', raw_text)

# Print how many blocks were found and show the first few characters of each
debug_info_clean = {
    "num_blocks_found": len(task_blocks_clean),
    "first_100_chars_each_block": [block[:100] for block in task_blocks_clean]
}
debug_info_clean

# Now that we have clean blocks, let's parse each one
tasks_data_clean = []

for i, block in enumerate(task_blocks_clean):
    task_id = f"task {i}"
    epochs = list(map(int, re.findall(r'Train Epoch: (\d+)', block)))
    train_losses = list(map(float, re.findall(r'Train Epoch: \d+, Loss: ([\d.]+)', block)))
    test_losses = list(map(float, re.findall(r'Test: Average loss: ([\d.]+)', block)))
    accuracies = list(map(float, re.findall(r'Accuracy: \d+/10000 \(([\d.]+)%\)', block)))

    tasks_data_clean.append({
        'task_id': task_id,
        'epochs': epochs,
        'train_losses': train_losses,
        'test_losses': test_losses,
        'accuracies': accuracies
    })

# Fix mismatch between epochs and metric lists by truncating to minimum length
for data in tasks_data_clean:
    min_len = min(len(data['epochs']), len(data['train_losses']), len(data['test_losses']), len(data['accuracies']))
    data['epochs'] = data['epochs'][:min_len]
    data['train_losses'] = data['train_losses'][:min_len]
    data['test_losses'] = data['test_losses'][:min_len]
    data['accuracies'] = data['accuracies'][:min_len]



# Map task IDs to specifications
task_labels = {
    "task 0": "task 0: base",
    "task 1": "task 1.1: avgpool",
    "task 2": "task 1.2: no maxpool + stride > 1",
    "task 3": "task 2: dropout",
    "task 4": "task 3: batchnorm",
    "task 5": "task 4: dropout + batchnorm"
}

# Apply labels to data
for i, data in enumerate(tasks_data_clean):
    task_id = f"task {i}"
    data['label'] = task_labels.get(task_id, task_id)

# Replot accuracy per epoch with new labels
plt.figure(figsize=(10, 6))
for data in tasks_data_clean:
    plt.plot(data['epochs'], data['accuracies'], label=data['label'])
plt.xlabel("Epoch")
plt.ylabel("Accuracy (%)")
plt.title("Accuracy over Epochs (Tasks 1-4)")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("acc_loss_tasks1_4.pdf")
plt.show()

